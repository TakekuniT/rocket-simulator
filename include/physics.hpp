#pragma once
#include <cmath>

namespace Physics {
    constexpr double g = 9.81;              // m/s^2
    constexpr double rho0 = 1.225;          // kg/m^3 (air density at sea level)
    constexpr double scaleHeight = 8500.0;  // m (altitude at which rocket scales)

    // calculates air density at given altitude
    inline double getAirDensity(double altitude) {
        return rho0 * std::pow(scaleHeight / altitude, 2);
        // return rho0 * exp(-altitude / scaleHeight);
    }
}