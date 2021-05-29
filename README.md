
[![Arduino CI](https://github.com/RobTillaart/relativity/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/relativity/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/relativity.svg?maxAge=3600)](https://github.com/RobTillaart/relativity/releases)


# relativity

Arduino library with relativity functions.


## Description

This library implements a number of functions that give indication of the 
time dilation etc due to relativistic speed.

The library is not extensively tested.

Educational purposes or when one put a cubesat into space :)

## Interface

- **relativity()** constructor
- **double factor(double speed)**
- **double gamma(double speed)**
- **double relativeTime(double time, double speed)** returns the relative time for given time and speed.
- **double relativeLength(double length, double speed)** returns the relative length for given length and speed.
- **double relativeMass(double mass, double speed)** returns the relative mass for given mass and speed.
- **double EnergyMass(double mass, double speed)** returns the energyMass for given mass and speed. Think E = mc^2.


### caching variants

These functions are the same however the math to calculate a given factor and gamma is done only once and cached. So these function will perform a bit better, especially if floating point is slow.

- **void setSpeed(double speed = 0)** set the speed once and calculate the factor and gamma to minimize math for next functions. Think caching.
- **double getSpeed()** returns speed set.
- **double getFactor()** returns factor for speed set
- **double getGamma()** returns gamma for speed set.
- **double relativeTime(double time)** returns the relative time for speed set with **setSpeed()**.
- **double relativeLength(double length)** returns the relative length for speed set.
- **double relativeMass(double mass)** returns the relative mass for speed set.
- **double EnergyMass(double mass)** returns the energy mass for for speed set.


### gravity effects

// to elaborate

- **double gravitationalTime(double time, double speed)**
- **double diameterEarth(uint8_t longitude = 45)** calculates the diameter of the Earth given it is not a nice circle but more an ellipse, flatter on the poles and thicker on the equator.
LOngitude is in (absolute) degrees.



## Operations

See examples for typical usage.


## Future

- test test test test
- add more functions
- fix some overflow conditions.


