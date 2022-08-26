// C++ primer: page 278
/*
    三个头文件对应三种输入输出流
    -iostream   -fstream    -sstream
*/
#include <iostream>
using std::cout; using std::cin; using std::endl;
#include <fstream>
using std::ifstream; using std::ofstream;
#include <string>
using std::string;

#include<unistd.h>


// 接受一个 istream&参数，返回值类型也是istream&, 必须从给定流中读取数据，打印到标准输出上
std::istream& TestIstream(std::istream& is){
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
    char *cwd = new char(50);
    getcwd(cwd, 50);
    string path(cwd);

    ifstream in(path);
    in.open(path + "/fstream.txt");
    if(in.is_open()){
        cout << "opened!!" << endl;
        in.close();
    }else   cout << "failed!" <<endl;
}
void StreamTest()
{
    // func: TestIstream()
    // std::istream& input = TestIstream(std::cin);
    // std::cout << input.rdstate() << endl;     
    Fstream();
}
