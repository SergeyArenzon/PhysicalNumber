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
PhysicalNumber();
double getNum();
Unit getUnit();



PhysicalNumber& operator++() ;
PhysicalNumber& operator++(int);
friend ostream& operator<< (ostream& os,  PhysicalNumber pn);
friend istream& operator>>(istream &input, PhysicalNumber& pn);
bool operator> (PhysicalNumber& other);
bool operator< (PhysicalNumber& other);
bool operator== (PhysicalNumber other);
bool operator!= (PhysicalNumber other);
bool operator<= (PhysicalNumber other);
bool operator>= (PhysicalNumber other);

PhysicalNumber& operator+=( PhysicalNumber other);
PhysicalNumber& operator-=( PhysicalNumber other);
PhysicalNumber& operator-- (int);
PhysicalNumber& operator-- ();
PhysicalNumber operator+ (PhysicalNumber other);
PhysicalNumber operator+ ();
PhysicalNumber operator- (PhysicalNumber other);
PhysicalNumber operator- ();







// friend PhysicalNumber& operator>>( istringstream  &input, PhysicalNumber &pn ) { 
//     string segment;
//     vector<std::string> seglist;
//     while(std::getline(input, segment, '[')) {    
//     seglist.push_back(segment);  
//     }         
//     seglist.at(1) = seglist.at(1).substr(0, seglist.at(1).length() - 1);  
//     istringstream ss(seglist.at(0));
//     int val;
//     ss >> val;
//     pn=PhysicalNumber(val , strToUnit(seglist.at(1)));
//     return pn;
//       }






 
   




// friend string operator-(PhysicalNumber& pn){
//     double x = -(pn.getNum());
//     ostringstream strs;
//     strs<<x;
//     string str = strs.str();
//     return str+"["+checkUnit(pn.getUnit())+"]";


// }

// friend bool operator> ( PhysicalNumber& pn,  PhysicalNumber& other){    
//     if (pn.getNum() > other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
//     else return false;
// }

// friend bool operator< ( PhysicalNumber& pn,  PhysicalNumber& other){    
//     if (pn.getNum() < other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
//     else return false;
// }

// friend bool operator== ( PhysicalNumber& pn,  PhysicalNumber& other){    
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true)  {
//     if (pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
//     }else throw runtime_error("Wrong units!");
//     return false;
// }


// friend bool operator== ( PhysicalNumber& pn,  PhysicalNumber other){
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true)  {
//     if (pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return true;
//     }else throw runtime_error("Wrong units!");
//     return false;
// }


// friend bool operator!= ( PhysicalNumber& pn,  PhysicalNumber& other){    
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true)  {
//     if (pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return false;
//     }else throw runtime_error("Wrong units!");
//     return true;
// }
// friend bool operator!= ( PhysicalNumber& pn,  PhysicalNumber other){    
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true)  {
//     if (pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) return false;
//     }else throw runtime_error("Wrong units!");
//     return true;
// }


// friend bool operator<= ( PhysicalNumber& pn,  PhysicalNumber& other){    
//     if ((pn.getNum() == other.getNum()*unitComputer(pn.getUnit(),other.getUnit())) ||  (pn.getNum() < other.getNum()*unitComputer(pn.getUnit(),other.getUnit()))) return true;
//     else return false;
// }

// friend PhysicalNumber& operator+=(PhysicalNumber& pn , PhysicalNumber other){
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true) {   
//         double x = pn.getNum()+other.getNum()*unitComputer(pn.getUnit(),other.getUnit()); 
//         pn.num = x;
//         return pn;
//     }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit(pn.getUnit())+"]");}
 
// }


// friend PhysicalNumber& operator-=(PhysicalNumber& pn , PhysicalNumber other){
//     if(ifDifUnit(pn.getUnit(),other.getUnit())==true) {   
//         double x = pn.getNum()-other.getNum()*unitComputer(pn.getUnit(),other.getUnit()); 
//         pn.num = x;
//         return pn;
//     }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit(pn.getUnit())+"]");}
 
// }
};
}