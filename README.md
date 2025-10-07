# Rocket Simulator

A simple C++ program that simulates the trajectory of a rocket, taking into account thrust, fuel burn, drag, and gravity.

## Compilation

Make sure you are in the project root directory, then run:

```bash
g++ src/main.cpp -Iinclude -o rocket_sim
```

## Running the SImulator

After compiling, run the simulator with

```bash
./rocket_sim
```

The code will prompt you for the rocket's name, mass, thrust, burn rate, and drag coefficient.

The program will generate a csv file in the output directory, which contains the time, altitude, velocity, and acceleration of the rocket at each time step.
