//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2021-05-29
// PURPOSE: unit tests for the relativity library
//          https://github.com/RobTillaart/TSL235R
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// ----------------------------
// assertEqual(expected, actual);               // a == b
// assertNotEqual(unwanted, actual);            // a != b
// assertComparativeEquivalent(expected, actual);    // abs(a - b) == 0 or (!(a > b) && !(a < b))
// assertComparativeNotEquivalent(unwanted, actual); // abs(a - b) > 0  or ((a > b) || (a < b))
// assertLess(upperBound, actual);              // a < b
// assertMore(lowerBound, actual);              // a > b
// assertLessOrEqual(upperBound, actual);       // a <= b
// assertMoreOrEqual(lowerBound, actual);       // a >= b
// assertTrue(actual);
// assertFalse(actual);
// assertNull(actual);

// // special cases for floats
// assertEqualFloat(expected, actual, epsilon);    // fabs(a - b) <= epsilon
// assertNotEqualFloat(unwanted, actual, epsilon); // fabs(a - b) >= epsilon
// assertInfinity(actual);                         // isinf(a)
// assertNotInfinity(actual);                      // !isinf(a)
// assertNAN(arg);                                 // isnan(a)
// assertNotNAN(arg);                              // !isnan(a)

#include <ArduinoUnitTests.h>


#include "Arduino.h"
#include "relativity.h"



unittest_setup()
{
}



unittest_teardown()
{
}



unittest(test_constructor)
{
  fprintf(stderr, "VERSION: %s\n", RELATIVITY_LIB_VERSION);

  relativity R;

  assertEqualFloat(299792458.0, R.getC(), 1);
  
}


unittest(test_alpha)
{
  relativity R;

// TODO test with factor and gamma
// loop

}


unittest(test_relativeTime)
{
  relativity R;

  for (double perc = 1; perc < 99.9999; perc += (100 - perc) / 10)
  {
    double v = R.getC() * perc * 0.01;

    Serial.print(" ");
    Serial.print(perc, 4);
    Serial.print("\t ");
    Serial.print(v * 0.001);
    Serial.print("\t ");
    Serial.print(R.relativeTime(1, v), 5);
    Serial.println();
  }
  Serial.println("done...");
}


unittest(test_relativeLength)
{
  relativity R;

  for (double perc = 1; perc < 99.9999; perc += (100 - perc) / 10)
  {
    double v = R.getC() * perc * 0.01;

    Serial.print(" ");
    Serial.print(perc, 4);
    Serial.print("\t ");
    Serial.print(v * 0.001);
    Serial.print("\t ");
    Serial.print(R.relativeLength(1, v), 5);
    Serial.println();
  }
  Serial.println("done...");
}


unittest(test_relativeMass)
{
  relativity R;

  for (double perc = 1; perc < 99.9999; perc += (100 - perc) / 10)
  {
    double v = R.getC() * perc * 0.01;

    Serial.print(" ");
    Serial.print(perc, 4);
    Serial.print("\t ");
    Serial.print(v * 0.001);
    Serial.print("\t ");
    Serial.print(R.relativeMass(1, v), 5);
    Serial.println();
  }
  Serial.println("done...");
}


unittest(test_EnergyMass)
{
  relativity R;

  for (double perc = 1; perc < 99.9999; perc += (100 - perc) / 10)
  {
    double v = R.getC() * perc * 0.01;

    Serial.print(" ");
    Serial.print(perc, 4);
    Serial.print("\t ");
    Serial.print(v * 0.001);
    Serial.print("\t ");
    Serial.print(R.EnergyMass(1, v), 5);
    Serial.println();
  }
  Serial.println("done...");
}


unittest(test_gravitationalTime)
{
  relativity R;

}


unittest(test_diameterEarth)
{
  relativity R;

}


unittest_main()


// --------
