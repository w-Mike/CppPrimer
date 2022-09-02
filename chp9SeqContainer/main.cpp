// C++ primer: page
/*

*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "func.h"

ifstream& getTestData()
{
    ifstream ifs("../../data/test.txt");

    // 返回 ifs
    return ifs;
}
int main()
{
    ifstream& ifs = getTestData();

    return 1;
}
