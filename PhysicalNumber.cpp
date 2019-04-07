#include <iostream>
#include "PhysicalNumber.h"
#include "math.h"
using namespace std;

ariel::PhysicalNumber::PhysicalNumber(int num ,Unit unit){
    this->num=num;
    this->unit=unit;
};
int ariel:: PhysicalNumber::getNum(){
    return num;
};

ariel::Unit ariel:: PhysicalNumber::getUnit(){
    return unit;    
};

 double ariel::unitComputer(int enm1,int enm2){
    if(0<=enm1<=2&&0<=enm2<=2){///c,m,km
       switch (enm1-(enm2))
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

// ariel::Unit ariel::strToUnit(string str){
//     if(str.compare("cm")) return Unit::CM;
//     else if(str.compare("m")) return Unit::M; 
//     else if(str.compare("km")) return Unit::KM;
//     else if(str.compare("sec")) return Unit::SEC;     
//     else if(str.compare("min")) return Unit::MIN;
          
          
          
        
//         // case 5:
//         //     return "hour";
//         //     break;
//         // case 6:
//         //     return "g";
//         //     break;
//         // case 7:
//         //     return "kg";
//         //     break;
//         // case 8:
//         //     return "ton";
//         //     break;
        


// }

