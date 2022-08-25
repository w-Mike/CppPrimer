// C++ primer: page 86
/*
    
*/
#include <iostream>
#include <vector>
#include <string>
using std::cout; using std::cin; using std::endl;
using std::vector; using std::string;

void VectorInit(){
    // 区分列表初始化的条件并不是使用{}还是(), 而是看提供的值能否用来初始化vector的数据类型
    // 列表初始化
    vector<string> vec1{"hi", "123"};
    //（默认）值初始化
    vector<string> vec2{10};
    vector<string> myVec{10,"12"}; 
    // vector<string> vec4("hi");   //没有该构造函数 
    
    // 访问元素和string类似
    for(auto &str : vec1){
        cout << str << endl;
    }
    
}

void VectorTest(){
    VectorInit();
}
