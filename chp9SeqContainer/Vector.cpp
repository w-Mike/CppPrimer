#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <fstream>
using std::ifstream;

#include <list>
using std::list;

vector<int>::const_iterator ifHave(vector<int>::const_iterator begin, vector<int>::const_iterator end, int num) // const_integor 可以读取指向的值，不能修改指向的值
{
    for (; begin != end; ++begin)
    {
        if (*begin == num)
            return begin;
    }
    return end;
}
void Ques9_12(ifstream &ifs)
{
    vector<int> vec;
    int buff;
    while (ifs >> buff)
    {
        vec.push_back(buff);
    }
    vector<int>::const_iterator iter = ifHave(vec.begin(), vec.end(), 123);
    if (iter != vec.end())
    {
        cout << iter - vec.begin() << endl;
    }
    else
    {
        std::cerr << "can't find!\n";
    }
}


void vectorTest(ifstream &ifs)
{
    Ques9_12(ifs);
}