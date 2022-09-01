// C++ primer: page 278
/*
    三个头文件对应三种输入输出流
    -iostream   -fstream    -sstream
*/
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <sstream>
using std::istringstream; using std::ostringstream;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include<unistd.h>      // 用于获取当前文件路径，通过getcwd函数可以确定要打开文件的绝对路径


// 接受一个 istream&参数，返回值类型也是istream&, 必须从给定流中读取数据，打印到标准输出上
std::istream& Istream(std::istream& is){
    int str;
    while(is >> str){
        cout << str << endl;
    }
    std::cout << is.rdstate() << endl;      // 6  如果到达文件结束符EOF（ctrl+D），eofbit和failbit都会置位 故为6
    is.clear();
    // is.clear(is.failbit);    4   由此看出 failbit在 0100位
    // std::cout << is.rdstate() << endl;

    // is.clear(is.eofbit);     2   由此 eofbit在0010位
    // std::cout << is.rdstate() << endl;
    return is;
}


void Fstream(){
    //  !!!!  注意 这里的相对路径 是相对于 可执行程序的路径 而不是源代码的路径，所以这里是相对于路径: ~/myCode/CppPrimer/build/chp8IO
    string filePath = "../../data/test.txt";
    ifstream ifs(filePath);
    if(ifs.is_open()){
        cout << "opened!!" << endl;
        string buff;
        while(getline(ifs, buff)){
            cout << buff << "-";
        }
        cout << endl;
        ifs.close();
    }else cout << "failed!" <<endl;
}
void wordFstream(){
    string filePath = "../../data/test.txt";
    ifstream ifs(filePath);
    if(ifs){
        string buff;
        vector<string> vec;
        while(ifs >> buff){
            vec.push_back(buff);
        }
        int n = 1;
        for(auto item:vec){
            cout << n << "--" << item << endl;
            ++n;
        }
    }
}
void Sstream(){

}

bool isDigit(string str){
    for(auto c:str){
        if(c > '9' || c < '0'){
            return false;
        }
    }
    return true;
}
void myTest(){
    // 功能：为每行字幕的末尾都添加一个空格;
    ifstream ifs("../../data/zimu.srt");
    ofstream ofs("../../data/xieru.srt");
    if(ifs.is_open() && ofs.is_open() ){
        string buff;
        int lineNum = 0;
        int seqNum = 3;
        while(getline(ifs, buff)){
            ++lineNum;
            if(lineNum == seqNum){
                buff += ' ';
                seqNum = seqNum + 4;
            }
            ofs << buff << endl;
        }
    }
    ifs.close();
    ofs.close();
}
void myTest2(){
    // 功能  把每段字幕的第一行删除
    ifstream ifs("../../data/zimu.srt");
    ofstream ofs("../../data/xieru.srt");
    if(ifs.is_open() && ofs.is_open() ){
        string buff;
        int pharaLine = 0;
        int lineNum = 0;
        while(getline(ifs, buff)){
            ++lineNum;
            if(isDigit(buff)){
                pharaLine = lineNum + 2;
            }
            if(lineNum != pharaLine){
                ofs << buff << endl;
            }
        }
    }
    ifs.close();
    ofs.close();
}
void StreamTest()
{
    // func: TestIstream()
    // std::istream& input = TestIstream(std::cin);
    // std::cout << input.rdstate() << endl;     
    myTest2();
}
