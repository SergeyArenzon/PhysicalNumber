#include <iostream>
#include <sstream>
using namespace std;
#include "Unit.h"
#include <vector>

namespace ariel{
    string checkUnit(int x);
    double unitComputer(int enm1, int enm2);
    Unit strToUnit(string str);
class PhysicalNumber{

ariel::Unit unit;
int num;
public:
PhysicalNumber(int num ,Unit unit);
friend ostream& operator<< (ostream& os,  PhysicalNumber& pn){
    os<<pn.getNum()<<"["<<ariel::checkUnit(pn.getUnit())<<"]";
    return os;
}

// friend PhysicalNumber& operator>>( string  &input, PhysicalNumber &pn ) { 
//     stringstream test(input);
//     string segment;
//     vector<std::string> seglist;

//     while(std::getline(test, segment, ('[',']')))
//     {
//          seglist.push_back(segment);           
//     }
    
//     std::istringstream ss(seglist.at(0));
//     ss >> val;


//    pn=PhysicalNumber(val , )
//     return 
//       }


friend string operator+ ( PhysicalNumber& pn,  PhysicalNumber& other){    
    double x= pn.getNum()+other.getNum()*unitComputer(pn.getUnit(),other.getUnit());   
    ostringstream strs;
    strs << x;
    string str = strs.str();
    return str+"["+checkUnit(pn.getUnit())+"]";
}

friend string operator- ( PhysicalNumber& pn,  PhysicalNumber& other){    
    double x=pn.getNum()-other.getNum()*unitComputer(pn.getUnit(),other.getUnit());   
    ostringstream strs;
    strs << x;
    string str = strs.str();
    return str+"["+checkUnit(pn.getUnit())+"]";
}


friend string operator-(PhysicalNumber& pn){
    double x = -(pn.getNum());
    ostringstream strs;
    strs<<x;
    string str = strs.str();
    return str+"["+checkUnit(pn.getUnit())+"]";


}

friend bool operator> ( PhysicalNumber& pn,  PhysicalNumber& other){    
    if (pn.getNum() > other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
    else return false;
}

friend bool operator< ( PhysicalNumber& pn,  PhysicalNumber& other){    
    if (pn.getNum() < other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
    else return false;
}

friend bool operator== ( PhysicalNumber& pn,  PhysicalNumber& other){    
    if (pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
    else return false;
}




friend bool operator<= ( PhysicalNumber& pn,  PhysicalNumber& other){    
    if ((pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) ||  (pn.getNum() < other.getNum()*unitComputer(pn.getUnit(),other.getUnit()))) return true;
    else return false;
}




int getNum();
Unit getUnit();

};



}