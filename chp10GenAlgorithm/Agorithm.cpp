#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <algorithm>
using std::count;
using std::fill;
using std::fill_n;
using std::find;

#include <list>
using std::list;

#include <sstream>
using std::istringstream;

#include <vector>
using std::vector;

#include <numeric>
using std::accumulate;

#include<iterator>
using std::back_inserter;

void Ques10_2(const string &testStr)
{
    istringstream iss(testStr);
    list<string> strList;
    string buff;
    while (iss >> buff)
    {
        strList.push_back(buff);
    }
    string val = "yellow";
    decltype(strList)::difference_type i = count(strList.begin(), strList.end(), val);
    decltype(strList)::iterator iter = find(strList.begin(), strList.end(), val);
    cout << i << endl;
    // cout << iter - strList.begin();   error：  只有随机访问的容器(内存顺序排列)的迭代器才可以进行加减运算。
}
void readAlgor(const string &testStr)
{
    // accumulate 将<迭代器对确定的序列和> 与 第三个参数 的和，类型可以不同，会转换为第三个参数的数据类型
    vector<double> vec;
    istringstream iss(testStr);
    double buff;
    while (iss >> buff)
    {
        vec.push_back(buff);
    }
    cout << accumulate(vec.begin(), vec.end(), 0) << endl; // warning： double会转换为int，以和 第三个参数想加，
}

void printVecInt(const vector<int> &vec)
{
    for (auto item : vec)
    {
        cout << item << "--";
    }
    cout << endl;
}
void writeAlgor(const string &testStr)
{
    // fill
    vector<int> vec{1, 2, 3, 4, 5, 6};
    fill(vec.begin(), vec.begin() + vec.size() / 2, 9);
    printVecInt(vec);

    // fill_n
    vector<int> vec2;
    // fill_n(vec2.begin(), 10, 0); // error:  不能向空容器调用fill_n;
    fill_n(vec.end(), vec.size()-2, 2); //发现不能这样，因为fill_n不会扩大容器的size
    printVecInt(vec);
    
    // 插入 迭代器 back_inserter
    fill_n(back_inserter(vec), vec.size(),7);
    printVecInt(vec);

    //copy
    

}

void test()
{
    string testStr("white white black white white black yellow");
    string testDouble("1.1 2.2 3.3");
    string testInt("1 2 34 54 5 2");
    // Ques10_2(testStr);
    // readAlgor(testDouble);
    writeAlgor(testInt);
}
