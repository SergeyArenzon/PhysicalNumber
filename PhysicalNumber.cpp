#include <iostream>
#include "PhysicalNumber.h"
#include "math.h"
#include <stdexcept>
using namespace std;
using namespace ariel;
ariel::PhysicalNumber::PhysicalNumber(double num ,Unit unit){

    this->num=num;
    this->unit=unit;
};
double ariel:: PhysicalNumber::getNum(){
    return num;
};
ariel::Unit ariel:: PhysicalNumber::getUnit(){
    return unit;    
};
double ariel::unitComputer(int enm1,int enm2){
    if(0<=enm1 && enm1<=2 && 0<=enm2 && enm2<=2){///c,m,km
       if(enm1==0&&enm2==1) return 100; //cm m
       else if(enm1==1&&enm2==0) return 0.01;//m cm
       else if(enm1==0&&enm2==2) return (1000*100); //cm km
       else if(enm1==2&&enm2==0) return 0.00001; //km cm
       else if(enm1==1&&enm2==2) return 1000;//m km
       else if(enm1==2&&enm2==1) return 0.001;//km m
       else if(enm1==0&&enm2==0) return 1;
       else if(enm1==1&&enm2==1) return 1;
       else if(enm1==2&&enm2==2) return 1;



    }
else if(3<=enm1 && enm1<=6 && 0<=enm2 && enm2<=6){///sec,min,hour
       switch (enm1 -(enm2))
       {
           case -2:
               return pow(10, 2); 
               break;
            case -1:
             return pow(60,1);
            break;

            case 0:
                return 1;
            case 1:
                return pow(60,-1);
                break;
            case 2:
                return pow(60,-2);
                break;

           default:
               break;
       }



    }
else if(6<=enm1 && enm1<=9&& 6<=enm2 && enm2<=9){///g,kg,ton
       switch (enm1 -(enm2))
       {
           case -2:
               return 1000*1000; 
               break;
            case -1:
             return 1000;
            break;

            case 0:
                return 1;
            case 1:
                return 0.001;

                break;
            case 2:
                return 0.000001;
                break;

           default:
               break;
       }



    }else{
        throw std::runtime_error("Units do not match - ["+ariel::checkUnit(enm2)+"] cannot be converted to ["+checkUnit(enm1)+"]");


}
    return false;  }
string ariel:: checkUnit(int x){

    switch (x)
    {
        case 0:
            return "cm";
            break;
        case 1:
            return "m";
            break;
        case 2:
            return "km";
            break;
        case 3:
            return "sec";
            break;
        case 4:
            return "min";
            break;
        case 5:
            return "hour";
            break;
        case 6:
            return "g";
            break;
        case 7:
            return "kg";
            break;
        case 8:
            return "ton";
            break;
        default:
            break;
    }

return "";}
ariel::Unit ariel::strToUnit(string str){
    
    if(str.compare("cm")==0) return Unit::CM;
    else if(str.compare("m")==0) return Unit::M; 
    else if(str.compare("km")==0) return Unit::KM;
    else if(str.compare("sec")==0) return Unit::SEC;     
    else if(str.compare("min")==0) return Unit::MIN;
    else if(str.compare("hour")==0) return Unit::HOUR;  
    else if(str.compare("g")==0) return Unit::G;      
    else if(str.compare("kg")==0) return Unit::KG;      
    else if(str.compare("ton")==0) return Unit::TON;    
return Unit::CM;
}
bool ariel::ifDifUnit(int x,int y){
    if(0<=x && x<=2 && 0<=y && y<=2) return true;
    else if(3<=x && x<=6 && 3<=y && y<=6) return true;
    else if(6<=x && x<=9 && 6<=y && y<=9) return true;
    return false;


}

/////////////////////operators////////////////////
ostream& ariel::operator<< (ostream& os, const PhysicalNumber& pn){
    os<<pn.num<<"["<<ariel::checkUnit(pn.unit)<<"]";
    return os;
}
istream& ariel::operator>>(istream &input, PhysicalNumber& pn) {
     
    string segment;
    vector<std::string> seglist;
    while(std::getline(input, segment, '[')) {    
    seglist.push_back(segment);  
    }         
    seglist.at(1) = seglist.at(1).substr(0, seglist.at(1).length() - 1);  
    istringstream ss(seglist.at(0));
    int val;
    ss >> val;
    pn=PhysicalNumber(val , strToUnit(seglist.at(1)));
    return input;
    
    }
PhysicalNumber PhysicalNumber::operator+() {
    return *this;
}
PhysicalNumber PhysicalNumber::operator-() {
    double x = -(this->num);

    PhysicalNumber a(x,this->unit);
     
     return a;
}
PhysicalNumber PhysicalNumber:: operator+ (const PhysicalNumber &other){
        
    if(!ifDifUnit(this->getUnit(),other.unit)){
        throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.unit)+"] cannot be converted to ["+ariel::checkUnit(this->getUnit())+"]");
    }
    double x= this->getNum()+other.num*unitComputer(this->getUnit(),other.unit); 
    Unit u(this->getUnit());  
    
    PhysicalNumber a(x,u);
    return a;
}
PhysicalNumber PhysicalNumber:: operator- (const PhysicalNumber& other){  
    if(!ifDifUnit(this->getUnit(),other.unit)
     )throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.unit)+"] cannot be converted to ["+ariel::checkUnit(this->getUnit())+"]");

    double x= this->getNum()-other.num*unitComputer(this->getUnit(),other.unit);   
    Unit u =this->unit;  
    PhysicalNumber a (x,u);
  
    return a;
}
bool PhysicalNumber::operator> (const PhysicalNumber&  other){
    if (this->getNum() > other.num*unitComputer(this->getUnit(),other.unit)) return true;
    else return false;
}
bool PhysicalNumber::operator< (const  PhysicalNumber&  other){
    if (this->getNum() < other.num*unitComputer(this->getUnit(),other.unit)) return true;
    else return false;
}
bool PhysicalNumber::operator== (const PhysicalNumber& other){
     
    if(ifDifUnit(this->getUnit(),other.unit)==true)  {
    if (this->getNum() == other.num*unitComputer(this->getUnit(),other.unit)) return true;
    }else 
        throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.unit)+"] cannot be converted to ["+ariel::checkUnit(this->getUnit())+"]");   
    return false;
}
bool PhysicalNumber::operator!= (const PhysicalNumber& other){
    if(ifDifUnit((*this).getUnit(),(*this).getUnit())==true)  {
    if ((*this).getNum() == other.num*unitComputer((*this).getUnit(),other.unit)) return false;
    }else throw runtime_error("Wrong units!");
    return true;
}
bool PhysicalNumber::operator<= (const PhysicalNumber& other){
    if (((*this).getNum() == other.num*unitComputer((*this).getUnit(),other.unit)) ||  ((*this).getNum() < (other.num)*unitComputer((*this).getUnit(),other.unit))) return true;
    else return false;
}
bool PhysicalNumber::operator>= (const PhysicalNumber& other){    
    if (((*this).getNum() == other.num*unitComputer((*this).getUnit(),other.unit)) ||  ((*this).getNum() > other.num*unitComputer((*this).getUnit(),other.unit))) return true;
    else return false;
}
PhysicalNumber& PhysicalNumber:: operator+=(const PhysicalNumber& other){
    if(ifDifUnit((*this).getUnit(),other.unit)==true) { 
        double x = (*this).getNum()+other.num*unitComputer((*this).getUnit(),other.unit); 
        (*this).num = x;
        return (*this);
    }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.unit)+"] cannot be converted to ["+ariel::checkUnit((*this).getUnit())+"]");}
 
}
PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& other){
    if(ifDifUnit((*this).getUnit(),other.unit)==true) {   
        double x = (*this).getNum()-other.num*unitComputer((*this).getUnit(),other.unit); 
        (*this).num = x;
        return (*this);
    }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.unit)+"] cannot be converted to ["+ariel::checkUnit((*this).getUnit())+"]");}
 
}
PhysicalNumber& PhysicalNumber::operator--(int) {
    PhysicalNumber temp(*this);
    this->num-=1;
    return temp;
}
PhysicalNumber &PhysicalNumber::operator--() {
    this->num -=1;
    return *this;
}
PhysicalNumber& PhysicalNumber::operator++(int) {
    PhysicalNumber temp(*this);
    this->num+=1;
    return temp;
}
PhysicalNumber &PhysicalNumber::operator++() {
    this->num +=1;
    return *this;
}
