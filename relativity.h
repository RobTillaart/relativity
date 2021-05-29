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

  double getC()
  { 
    return c;
  };

  
  double factor(double speed)
  {
    double alpha = speed * divc;
    return sqrt(1 - alpha * alpha);
  }
  
  double gamma(double speed)
  {
    return 1 - factor(speed);
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
    return relativeMass(mass, speed) * c * c;
  }


///////////////////////////////////////////////////////////////////
//
// relativistic corrections for gravity
//

  double gravitationalTime(double time, double speed)
  {
    return time * factor(speed);
  }

  // returns diameter in km.
  double diameterEarth(uint8_t longitude = 45)  // 0..90
  {
    // https://www.youtube.com/watch?v=hYMvJum9_Do  @ 8:00
    // radius polar:    6357 km
    // radius equator:  6378 km
    // difference:      21 km      
    double radians = longitude * (PI / 180.0);

    // approx of the graph in youtube with a cosine
    return 6367.5 + 10.5 * cos(radians * 2);
  }

  private:
  
  const double c = 299792458.0;
  const double divc = 1.0/c;


};

// -- END OF FILE --
