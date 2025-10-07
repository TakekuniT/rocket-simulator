#include <iostream>
#include <fstream>
#include <cmath>
#include "rocket.hpp"
#include "physics.hpp"


int main() {

    Rocket rocket = {
        "test rocket",
        50.0,
        20.0,
        1500.0,
        0.5,
        0.3,
        0.1
    };

    double dt = 0.01;
    double t = 0.0;
    double altitude = 0.0;
    double velocity = 0.0;
    double fuel = rocket.fuelMass;

    std::ofstream file("trajectory.csv");
    file << "time,altitude,velocity,acceleration" << std::endl;
    while (altitude >= 0.0) {
        double mass = rocket.massDry + fuel;
        double airDensity = Physics::getAirDensity(altitude);
        double drag = 0.5 * airDensity * rocket.dragCoeff * rocket.area * velocity * velocity;
        if (velocity > 0) drag *= -1;

        double thrust = (fuel > 0) ? rocket.thrust : 0.0;
        double weight = mass * Physics::g;
        double force = thrust - drag - weight;

        double acceleration = force / mass;

        velocity += acceleration * dt;
        altitude += velocity * dt;
        t += dt;

        // burn fuel
        if (fuel > 0) {
            fuel -= rocket.burnRate * dt;
            if (fuel < 0) fuel = 0;
        }

        file << t << "," << altitude << "," << velocity << "," << acceleration << std::endl;
        if (altitude < 0 && t > 2) break;
    }
    file.close();
    std::cout << "Simulation complete, results saved to trajectory.csv" << std::endl;
}