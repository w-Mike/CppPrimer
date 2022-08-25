// C++ Primer -- Page76 标准库类型String基本介绍
/*
*/
#include <string>
#include <iostream>
#include <cctype>
extern int quanju;

using std::string;
using std::cout; using std::endl; 

void StringInit(){
    string str1("adc");   //直接初始化
    string str2 = "abc";  //拷贝初始化
    string str3(3, 'b');  //需要多个参数来进行初始化，只能用直接初始化
    string str4;          
    string str5("");            
    if(str4 == str5){
        cout << "same" << std::endl;     // 说明 默认初始化的值为 ""
    }

    string str6("123");
    string str7 = str1 + "123";      //当string与字符串字面值混合运算时，其中一个是string就可以正常运算
    // string str2 = "21" + "12";   因为字符串字面值是一个字符数组， 字符数组没有 + 运算符运算
}

void StringSize(){
    string str = "123";
    cout << str.size() << endl;
}

// C11的新特性: for循环
void forString(){
    string myStr = "MineCraft";
    for(auto c : myStr){
        cout<<c<<endl;
    }
    
    // decltype 可以获取实参的数据类型，如果参数是一个 “指针的解引用” 则返回的类型为引用  其他细节看书 
    decltype(myStr) str = "213";
    decltype(myStr.size()) upperCnt = 0;
    // <==>  size_t upperCnt = 0; 
    
    for(auto c : myStr){
        if(isupper(c))
            ++upperCnt;
    }
    cout << "The number of uppercase letters in "+ myStr + ":" << upperCnt << endl;
    for(auto &c : myStr){
        c = tolower(c);
    }
    cout << "Changed myStr is:" << myStr <<endl;
}


void StringTest(){
    forString();
}
