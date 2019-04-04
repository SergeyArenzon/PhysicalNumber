
#include <iostream>
#include "PhysicalNumber.h"

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



