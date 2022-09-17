// C++ primer: page 278
/*
    三个头文件对应三种输入输出流
    -iostream   -fstream    -sstream
*/

/*
总结： 理解 IO流的概念的关键就是：
    清楚每个流对象 从 <哪里> 读取,写入 <哪里> -- (其实从语句中的>> << 符号的方向就可以简单理解)
    <变量>指 普通变量/字符串字面量

        (istream对象)
        cin 从 <命令行> 读取， 写入<变量>        (命令行 >> cin) >> variable;
        cout 从 <变量> 读取，写入<命令行>        (命令行<< cout) << variable;

        ifstream对象 从 <文件> 读取， 写入 <变量>    (文件 >> ifstream) >> variable
        ofstream对象 从 <变量> 读取， 写入 <文件>    (文件 << ofstream) << variable

        istringstream对象 从 <字符串对象> 读取, 写入 <变量> (字符串 >> istringstream >> 变量)
        ostringstream对象 从 <变量> 读取,  写入 <oss的字符串成员变量> (oss.str() << oss << 变量)
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
using std::ofstream;
#include <sstream>
using std::istringstream;
using std::ostringstream;
#include <string>
using std::string;

#include <vector>
using std::vector;

#include <unistd.h> // 用于获取当前文件路径，通过getcwd函数可以确定要打开文件的绝对路径

// 接受一个 istream&参数，返回值类型也是istream&, 必须从给定流中读取数据，打印到标准输出上
std::istream &Istream(std::istream &is)
{
    int str;
    while (is >> str)
    {
        cout << str << endl;
    }
    std::cout << is.rdstate() << endl; // 6  如果到达文件结束符EOF（ctrl+D），eofbit和failbit都会置位 故为6
    is.clear();
    // is.clear(is.failbit);    4   由此看出 failbit在 0100位
    // std::cout << is.rdstate() << endl;

    // is.clear(is.eofbit);     2   由此 eofbit在0010位
    // std::cout << is.rdstate() << endl;
    return is;
}

void Fstream()
{
    //  !!!!  注意 这里的相对路径 是相对于 可执行程序的路径 而不是源代码的路径，所以这里是相对于路径: ~/myCode/CppPrimer/build/chp8IO
    string filePath = "../../data/test.txt";
    ifstream ifs(filePath);
    if (ifs.is_open())
    {
        cout << "opened!!" << endl;
        string buff;
        while (getline(ifs, buff))
        {
            cout << buff << "-";
        }
        cout << endl;
        ifs.close();
    }
    else
        cout << "failed!" << endl;
}
void wordFstream()
{
    string filePath = "../../data/test.txt";
    ifstream ifs(filePath);
    if (ifs)
    {
        string buff;
        vector<string> vec;
        while (ifs >> buff)
        {
            vec.push_back(buff);
        }
        int n = 1;
        for (auto item : vec)
        {
            cout << n << "--" << item << endl;
            ++n;
        }
    }
}
void Sstream()
{
    vector<string> buffData;
    string buff;
    getline(cin, buff);
    istringstream iss(buff); // istringstream对象从buff字符串中读取(buff>>iss),
                             // 向其他变量写入 (iss >> variable)
    string phra;
    while (iss >> phra)
    {
        buffData.push_back(phra);
    }

    ostringstream oss;
    for (const auto &data : buffData)
    {
        oss << data << "==="; // ostringstream对象从变量或者字符串字面值读取，输出到oss.str()字符串对象中。
    }
    cout << oss.str();
}
struct personInfo
{
    /* data */
    string name;
    vector<string> nums;
};

void practice8_11()
{
    vector<personInfo> personVec;
    string line, num;
    istringstream iss;
    while (getline(cin, line))
    {
        personInfo item;
        iss.str(line);
        iss >> item.name;
        while (iss >> num)
        {
            /* code */
            item.nums.push_back(num);
        }
        personVec.push_back(item);
        iss.clear();
    }

    for (const auto &person : personVec)
    {
        cout << person.name << "---";
        for (const auto &num : person.nums)
        {
            cout << num << ",";
        }
        cout << endl;
    }
}

#pragma region MyTest
bool isDigit(string str)
{
    for (auto c : str)
    {
        if (c > '9' || c < '0')
        {
            return false;
        }
    }
    return true;
}
void myTest()
{
    // 功能：为每行字幕的末尾都添加一个空格;
    ifstream ifs("../../data/zimu.srt");
    ofstream ofs("../../data/xieru.srt");
    if (ifs.is_open() && ofs.is_open())
    {
        string buff;
        int lineNum = 0;
        int seqNum = 3;
        while (getline(ifs, buff))
        {
            ++lineNum;
            if (lineNum == seqNum)
            {
                buff += ' ';
                seqNum = seqNum + 4;
            }
            ofs << buff << endl;
        }
    }
    ifs.close();
    ofs.close();
}
void myTest2()
{
    // 功能  把每段字幕的第一行删除
    ifstream ifs("../../data/zimu.srt");
    ofstream ofs("../../data/xieru.srt");
    if (ifs.is_open() && ofs.is_open())
    {
        string buff;
        int pharaLine = 0;
        int lineNum = 0;
        while (getline(ifs, buff))
        {
            ++lineNum;
            if (isDigit(buff))
            {
                pharaLine = lineNum + 2;
            }
            if (lineNum != pharaLine)
            {
                ofs << buff << endl;
            }
        }
    }
    ifs.close();
    ofs.close();
}
#pragma endregion

void StreamTest()
{
    // func: TestIstream()
    // std::istream& input = TestIstream(std::cin);
    // std::cout << input.rdstate() << endl;
    practice8_11();
}
