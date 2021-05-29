#pragma once
//
//    FILE: relativity.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.0
// PURPOSE: Collection relativity formulas
//     URL: https://github.com/RobTillaart/relativity
//
//  HISTORY:
//  0.1.0   2021-05-29  initial version


#include "Arduino.h"


#define RELATIVITY_LIB_VERSION        (F("0.1.0"))


class relativity
{
public:

  relativity()
  {
    double _speed  = 0.0;
    double _factor = 1.0;
    double _gamma  = 1.0;
  }

  double getC()
  { 
    return _c;
  };

  double getG()
  { 
    return _G;
  };

  
  double factor(double speed)
  {
    double alpha = speed * _divc;
    return sqrt(1 - alpha * alpha);
  }
  
  double gamma(double speed)
  {
    return 1.0 / factor(speed);
  }
  
///////////////////////////////////////////////////////////////////
//
// relativistic corrections for speed
//

  double relativeTime(double time, double speed)
  {
    return time * factor(speed);
  }

  double relativeLength(double length, double speed)
  {
    return length * factor(speed);
  }

  double relativeMass(double mass, double speed)
  {
    return mass / factor(speed);
  }

  double EnergyMass(double mass, double speed)
  {
    return relativeMass(mass, speed) * _c2;
  }


  // set speed only once for the 3 values
  void setSpeed(double speed = 0)
  {
    _speed = speed;
    _factor = factor(speed);
    _gamma = gamma(speed);
  }

  double getSpeed()
  {
    return _speed;
  }

  double relativeTime(double time)
  {
    return time * _factor;
  }

  double relativeLength(double length)
  {
    return length * _factor;
  }

  double relativeMass(double mass)
  {
    return mass * _gamma;
  }

  double EnergyMass(double mass)
  {
    return relativeMass(mass) * _c2;
  }


///////////////////////////////////////////////////////////////////
//
// relativistic corrections for gravity
//

  double gravitationalTime(double time, double mass, double radius)
  {
    // formula tries to stay within float range
    return time / sqrt(1 - (mass / (radius * _c2)) * (2 * _G) );
  }

  // returns radius in km.
  double radiusEarth(uint8_t longitude = 45)  // 0..90
  {
    // https://www.youtube.com/watch?v=hYMvJum9_Do  @ 8:00
    // radius polar:    6357 km
    // radius equator:  6378 km
    // difference:      21 km      
    double radians = longitude * (PI / 180.0);

    // approx of the graph in youtube with a cosine
    return 6367.5 + 10.5 * cos(radians * 2);
  }

  // mass in 
  double getPlanetMass(uint8_t n)  // sun = 0; mercury = 1 etc
  {
    return massPlanets[n];
  }

  // radius in km
  double getPlanetRadius(uint8_t n)  // sun = 0; mercury = 1 etc
  {
    // todo
    return 0;
  }


private:

  const double _c = 299792458.0;        // speed of light
  const double _c2 = _c * _c;           // sol squared
  const double _divc = 1.0/_c;          // sol inverse

  const double _G = 6.6742e-11;         // gravitational constant

  const double massPlanets[4] =
  {
    1.9891e30,      // mass Sun
    0,
    0,
    5.97219e24,     // mass earth
  };

  const double radiusPlanets[4] =
  {
    6.96342e5,      // radius Sun
    0,
    0,
    6.371e3,        // radius earth
  };

  // cache
  double _speed  = 0.0;
  double _factor = 1.0;
  double _gamma  = 1.0;
};


// -- END OF FILE --
