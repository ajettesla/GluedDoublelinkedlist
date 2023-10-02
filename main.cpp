#include <iostream>
#include "gludll.h"




int main(){

gdll a(0, "ajet");

a.pushData(1,"anroop");
a.pushData(2,"whatiscooking");
a.pushData(3,"ok");
a.pushDataat(4,"nothing", 2);
std::cout <<"----------------------"<<std::endl;
a.printData();
a.deleteData(3);
std::cout <<"----------------------"<<std::endl;
a.printData();
   


return 0;
}