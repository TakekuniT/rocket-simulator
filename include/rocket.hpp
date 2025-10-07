#pragma once
#include <string>

struct Rocket {
    std::string name;
    double massDry;     // kg without fuel
    double fuelMass;    // kg
    double thrust;      // N
    double burnRate;    // kg/s
    double area;        // m^2
};