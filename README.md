
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

### relativity effects

- **double relativeTime(double time, double speed)**
- **double relativeLength(double length, double speed)**
- **double relativeMass(double mass, double speed)**
- **double EnergyMass(double mass, double speed)**


### gravity effects

- **double gravitationalTime(double time, double speed)**
- **double diameterEarth(uint8_t longitude = 45)**



## Operations

See examples for typical usage.


## Future

- add more functions
- fix some overflow conditions.


