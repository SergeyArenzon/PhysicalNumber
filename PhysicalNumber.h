#include <iostream>
#include <sstream>
using namespace std;
#include "Unit.h"

namespace ariel{
    string checkUnit(int x);
    double unitComputer(int enm1, int enm2);
class PhysicalNumber{

ariel::Unit unit;
int num;
public:
PhysicalNumber(int num ,Unit unit);
friend ostream& operator<< (ostream& os,  PhysicalNumber& pn){
    os<<pn.getNum()<<"["<<ariel::checkUnit(pn.getUnit())<<"]";
    return os;
}
friend string operator+ ( PhysicalNumber& pn,  PhysicalNumber& other){
     
    double x= pn.getNum()+other.getNum()*unitComputer(pn.getUnit(),other.getUnit());
    
    ostringstream strs;
    strs << x;
    string str = strs.str();
    return str;
}

int getNum();
Unit getUnit();

};



}