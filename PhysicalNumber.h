#include <iostream>
#include <sstream>
using namespace std;
#include "Unit.h"

namespace ariel{
class PhysicalNumber{

ariel::Unit unit;
int num;
public:
PhysicalNumber(int num ,Unit unit);
friend ostream& operator<< (ostream& os,  PhysicalNumber& pn){

    os<<pn.getNum()<<"["<<"]";
    return os;
}
int getNum();
Unit getUnit();

};



}