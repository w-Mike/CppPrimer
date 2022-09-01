// C++ primer: page 
/*

*/
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <string>
using std::string;

int add(int a, int b){return a+b;}

int funcPoint(){
    typedef int (*pf)(int ,int ) ;
    
    return 1;
}

void funcPointTest(){
    funcPoint();
}




