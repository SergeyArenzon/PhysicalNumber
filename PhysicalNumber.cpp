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
if(3<=enm1 && enm1<=6 && 0<=enm2 && enm2<=6){///sec,min,hour
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
if(6<=enm1 && enm1<=9&& 6<=enm2 && enm2<=9){///g,kg,ton
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



    }

 }

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

}

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
    throw std::runtime_error("Bad input unit");
}

bool ariel::ifDifUnit(int x,int y){
    if(0<=x && x<=2 && 0<=y && y<=2) return true;
    else if(3<=x && x<=6 && 3<=y && y<=6) return true;
    else if(6<=x && x<=9 && 6<=y && y<=9) return true;
    return false;


}





ostream& ariel::operator<< (ostream& os,  PhysicalNumber pn){//<<
    os<<pn.getNum()<<"["<<ariel::checkUnit(pn.getUnit())<<"]";
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
 PhysicalNumber PhysicalNumber:: operator+ (PhysicalNumber other){ 
        
    if(!ifDifUnit(this->getUnit(),other.getUnit())){
        throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit(this->getUnit())+"]");
    }
    double x= this->getNum()+other.getNum()*unitComputer(this->getUnit(),other.getUnit()); 
    Unit u(this->getUnit());  
    
    PhysicalNumber a(x,u);
    return a;
}
PhysicalNumber PhysicalNumber:: operator- (PhysicalNumber other){  
    if(!ifDifUnit(this->getUnit(),other.getUnit())
     )throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit(this->getUnit())+"]");

    double x= this->getNum()-other.getNum()*unitComputer(this->getUnit(),other.getUnit());   
    Unit u =this->unit;  
    PhysicalNumber a (x,u);
  
    return a;
}
 bool PhysicalNumber::operator> ( PhysicalNumber& other){ 
    
    if (this->getNum() > other.getNum()*unitComputer(this->getUnit(),other.getUnit())) return true;
    else return false;
}
 bool PhysicalNumber::operator< (  PhysicalNumber& other){    
    if (this->getNum() < other.getNum()*unitComputer(this->getUnit(),other.getUnit())) return true;
    else return false;
}
 bool PhysicalNumber::operator== (PhysicalNumber other){
    if(ifDifUnit(this->getUnit(),other.getUnit())==true)  {
    if (this->getNum() == other.getNum()*unitComputer(this->getUnit(),other.getUnit())) return true;
    }else throw runtime_error("Wrong units!");
    return false;
}
 bool PhysicalNumber::operator!= (PhysicalNumber other){    
    if(ifDifUnit((*this).getUnit(),(*this).getUnit())==true)  {
    if ((*this).getNum() == other.getNum()*unitComputer((*this).getUnit(),other.getUnit())) return false;
    }else throw runtime_error("Wrong units!");
    return true;
}
 bool PhysicalNumber::operator<= (PhysicalNumber other){    
    if (((*this).getNum() == other.getNum()*unitComputer((*this).getUnit(),other.getUnit())) ||  ((*this).getNum() < other.getNum()*unitComputer((*this).getUnit(),other.getUnit()))) return true;
    else return false;
}
PhysicalNumber& PhysicalNumber:: operator+=( PhysicalNumber other){
    if(ifDifUnit((*this).getUnit(),other.getUnit())==true) { 
        double x = (*this).getNum()+other.getNum()*unitComputer((*this).getUnit(),other.getUnit()); 
        (*this).num = x;
        return (*this);
    }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit((*this).getUnit())+"]");}
 
}
PhysicalNumber& PhysicalNumber::operator-=(PhysicalNumber other){
    if(ifDifUnit((*this).getUnit(),other.getUnit())==true) {   
        double x = (*this).getNum()-other.getNum()*unitComputer((*this).getUnit(),other.getUnit()); 
        (*this).num = x;
        return (*this);
    }else {throw std::runtime_error("Units do not match - ["+ariel::checkUnit(other.getUnit())+"] cannot be converted to ["+ariel::checkUnit((*this).getUnit())+"]");}
 
}
 PhysicalNumber& PhysicalNumber::operator--(int) {
    this->num -=1;
    return *this;
}
PhysicalNumber &PhysicalNumber::operator--() {
    this->num -=1;
    return *this;
}
 PhysicalNumber& PhysicalNumber::operator++(int) {

    this->num+=1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator++() {
    this->num +=1;
    return *this;
}
bool PhysicalNumber::operator>= (PhysicalNumber other){    
    if (((*this).getNum() == other.getNum()*unitComputer((*this).getUnit(),other.getUnit())) ||  ((*this).getNum() > other.getNum()*unitComputer((*this).getUnit(),other.getUnit()))) return true;
    else return false;
}