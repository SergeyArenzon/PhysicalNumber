#include <iostream>
#include "PhysicalNumber.h"
#include "math.h"
#include <stdexcept>
using namespace std;

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
       switch (enm1 -(enm2))
       {
           case -2:
               return pow(10, 4); 
               break;
            case -1:
             return pow(10,3);
            break;

            case 0:
                return 1;
            case 1:
                return pow(10,-3);
                break;
            case 2:
                return pow(10,-4);
                break;

           default:
               break;
       }



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
               return pow(10, 4); 
               break;
            case -1:
             return pow(10,3);
            break;

            case 0:
                return 1;
            case 1:
                return pow(10,-3);
                break;
            case 2:
                return pow(10,-4);
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