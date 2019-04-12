#include <iostream>
#include <sstream>
using namespace std;
#include "Unit.h"
#include <vector>
#include <sstream>
#include <stdexcept>
namespace ariel{
    string checkUnit(int x);
    double unitComputer(int enm1, int enm2);
    Unit strToUnit(string str);
    bool ifDifUnit(int x,int y);
    
 
    

class PhysicalNumber{

ariel::Unit unit;
double num;
public:
PhysicalNumber(double num ,Unit unit);
double getNum();
Unit getUnit();



PhysicalNumber& operator++() ;
PhysicalNumber& operator++(int);
friend ostream& operator<< (ostream& os, const PhysicalNumber& pn);
friend istream& operator>>(istream &input, PhysicalNumber& pn);
bool operator> (const PhysicalNumber& other);
bool operator< (const PhysicalNumber& other);
bool operator== (const PhysicalNumber& other);
bool operator!= (const PhysicalNumber &other);
bool operator<= (const PhysicalNumber &other);
bool operator>= ( const PhysicalNumber &other);
PhysicalNumber& operator+=( const PhysicalNumber& other);
PhysicalNumber& operator-=( const PhysicalNumber &other);
PhysicalNumber& operator-- (int);
PhysicalNumber& operator-- ();
PhysicalNumber operator+ (const PhysicalNumber& other);
PhysicalNumber operator+ ();
PhysicalNumber operator- (const PhysicalNumber& other);
PhysicalNumber operator- ();



};
}