// C++ primer: page 
/*
    
*/
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl;
using std::string; using std::vector;


// string和绝大多数STL容器都支持iterator.
void Iterator(){
    //iterator 不支持>, <等的比较(string和vector容器除外)，只支持==或！=， 所以用iterator来访问string或其他容器的时候为
    // 当指针用吧，可以解引用
    string str = "minecraft";
    for(auto iter = str.begin(); iter != str.end(); ++iter){
        *iter = 'a';
    }
    // C11特性：利用cbegin返回常量iterator, 只能读不能写
    for(auto iter = str.cbegin(); iter != str.cend(); ++iter){
        // *iter = '2';  X
        cout << *iter << " ";
    }
    cout << endl;

    // string 与 vector的iterator 提供了额外的iterator的运算： + - += -= < <= > >=
    vector<int> vec{0,1,2,3,4,5};
    auto b = vec.begin();
    auto e = vec.end();
    cout << "e-b=" << e - b << endl;
    cout << "*b=" << *b << endl;
    cout << "*(b+=3) = " << *(b+=3) << endl;
}

//二分查找
int MidSearch(vector<int> vec, int num){
    // 还有个前提：begin与end差偶数格时，mid(begin + (end-begin)/2 )总会偏向左半边，
    // 只用考虑两格 与 三格的情况
    // 1. vec存在num，最终都会有两种情况（即使num在mid左右的区域，最终也会来到这俩情况的）
    //                      ---num在mid上:直接return了  ---num在两端：mid最后总会到两端的（所以最终只会一种情况也就是num在中间，因为判断条件就是if（*mid==num） return）
    // 2. vec不存在num，不论任何情况，begin,end和mid都会最终指向同一个数字，
    //                  然后判断mid！=num ==> begin右移或者 end左移 ==> begin>end
    // 总结 退出循环的条件：1，begin > end(在循环判断中) 2，*mid == num(在循环体中)

    // 一句话 vec存在num，最终mid会指向num， vec不存在num，最终begin会 > end
    auto begin = vec.begin();
    auto end = vec.end();
    auto mid = begin + ((end-begin)>>1);
    while(begin <= end){
        mid = begin + ((end - begin)>>1);
        if(*mid == num) return (mid - vec.begin());
        if(num < *mid) end = mid - 1;
        if(num > *mid) begin = mid + 1;
    }
    return -1;
}
bool isInteger(string str){
    for(char c:str) 
        if(c < '0' || c > '9')  return false;
    return true;
}
inline int strToint(string str){
    return atoi(str.c_str());
}
void printVec(vector<int> &vec){
    auto beg = vec.begin();
    for(auto i = vec.begin(); i != vec.end(); ++i) cout << i - beg << ":" << *i <<" ";
    cout << endl;
}
void TestMidSearch(){
    vector<int> vec;
    string str;
    while(getline(cin, str)){
        if(str == "c") break;
        if(isInteger(str) && str!="")  vec.push_back(strToint(str));
        else cout << "NaN\n";
    }
    printVec(vec);
    while(getline(cin, str)){
        printVec(vec);
        if(str == "c") break;
        if(isInteger(str)) cout << strToint(str) << " at:" << MidSearch(vec, strToint(str)) << endl;
        else cout << "NaN\n";
    }
}
int search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    int mid = begin + ((end - begin)/2);
    while(begin <= end){
        if(target == nums[mid]) return mid;
        if(target < nums[mid]) end = mid - 1;
        if(target > nums[mid]) begin = mid + 1;
        mid = begin + ((end - begin)/2);
    }
    return -1;
}
void IteratorTest(){
    // TestMidSearch();
    vector<int> vec{1};
    cout << search(vec, -1);
}   

