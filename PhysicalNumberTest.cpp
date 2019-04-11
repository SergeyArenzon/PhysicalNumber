/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    
    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d) 
    

.setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
   
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT
      .setname("Basic output")
      .CHECK_OUTPUT(c, "2[hour]")
      .CHECK_OUTPUT(d, "30[min]")

      .setname("Compatible dimensions")
      .CHECK_OUTPUT(c+d,"2.5[hour]")
      .CHECK_OUTPUT(d+c,"150[min]")
      .CHECK_OUTPUT(c-c,"0[hour]")
      .CHECK_OUTPUT(c-d,"1.5[hour]")
      .CHECK_OUTPUT(d-c,"-90[min]")
      .CHECK_OUTPUT(-c,"-2[hour]")
      .CHECK_OUTPUT(d+d,"60[min]")
      .CHECK_OUTPUT((c+=d), "2.5[hour]")
      .CHECK_OUTPUT(c, "2.5[hour]")
      .CHECK_OUTPUT(++c, "3.5[hour]")


      .setname("Incompatible dimensions")
      .CHECK_THROWS(c+a)
      .CHECK_THROWS(c+b)
      .CHECK_THROWS(d+a)
      .CHECK_THROWS(d+b)
      .CHECK_THROWS(a-c)
      

      .setname("Basic input")
      .CHECK_OK(istringstream("30[min]") >> c)
      .CHECK_OUTPUT(d+c, "60[min]")
      .CHECK_OK(istringstream("30[hour]") >> c)
      .CHECK_OUTPUT(c+d, "30.5[hour]")
      .setname("...")

      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}

