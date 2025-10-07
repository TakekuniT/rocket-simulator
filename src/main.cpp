#include <iostream>
#include <fstream>
#include <cmath>
#include "rocket.hpp"
#include "physics.hpp"


int main() {

    // Sample rocket data
    // Rocket rocket = {
    //     "test rocket",
    //     50.0,       // dry mass (kg)
    //     20.0,       // fuel mass (kg)
    //     1500.0,     // thrust (N)
    //     0.5,        // burn rate (kg/s)
    //     0.3,        // drag coefficient
    //     0.1         // cross-sectional area (m^2)
    // };

    Rocket rocket;


    // Get user input
    std::cout << "Enter rocket name: ";
    std::getline(std::cin, rocket.name);
    std::cout << "Enter dry mass (kg): ";
    std::cin >> rocket.massDry;
    std::cout << "Enter fuel mass (kg): ";
    std::cin >> rocket.fuelMass;
    std::cout << "Enter thrust (N): ";
    std::cin >> rocket.thrust;
    std::cout << "Enter burn rate (kg/s): ";
    std::cin >> rocket.burnRate;
    std::cout << "Enter drag coefficient: ";
    std::cin >> rocket.dragCoeff;
    std::cout << "Enter cross-sectional area (m^2): ";
    std::cin >> rocket.area;
    std::cout << std::endl;

    double dt = 0.01;                   // time step (s)
    double t = 0.0;                     // simulation start time (s)
    double altitude = 0.0;              // initial altitude (m)
    double velocity = 0.0;              // initial velocity (m/s)
    double fuel = rocket.fuelMass;      // initial fuel mass (kg)


    std::string filename = "output/csv/" + rocket.name + ".csv";
    std::ofstream file(filename);
    file << "time,altitude,velocity,acceleration" << std::endl;

    // simulation continues until rocket hits the ground
    while (altitude >= 0.0) {
        // m(t) = m_dry + m_fuel(t)
        // mass at given time
        double mass = rocket.massDry + fuel;

        // rho(h) = rho_0 * e^(-h/H)
        // air density at given altitude
        double airDensity = Physics::getAirDensity(altitude);

        // D = 1/2 * rho(h) * C_d * A * v^2
        // drag force
        double drag = 0.5 * airDensity * rocket.dragCoeff * rocket.area * velocity * velocity;
        if (velocity > 0) drag *= -1;

        // thrust at given fuel
        double thrust = (fuel > 0) ? rocket.thrust : 0.0;

        // W(t) = m(t) * g
        // weight at given time
        double weight = mass * Physics::g;

        // F_net = T - D - W
        // net force
        double force = thrust - drag - weight;

        // a(t) = F_net / m(t)
        // acceleration at given time
        double acceleration = force / mass;

        // v_(n+1) = v_n + a(t) * dt
        // velocity at next time step
        velocity += acceleration * dt;

        // h_(n+1) = h_n + v_(n+1) * dt
        // altitude at next time step
        altitude += velocity * dt;

        // t_(n+1) = t_n + dt
        // increment time
        t += dt;


        // m_fuel(t+dt) = m_fuel(t) - m_fuel(dt)
        // burn fuel
        if (fuel > 0) {
            fuel -= rocket.burnRate * dt;
            if (fuel < 0) fuel = 0;
        }

        // saves data to CSV
        file << t << "," << altitude << "," << velocity << "," << acceleration << std::endl;
        if (altitude < 0 && t > 2) break;
    }
    file.close();
    std::cout << "Simulation complete, results saved as csv file." << std::endl;
}