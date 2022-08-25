// Page 55  Const引用

// 既然有常量， 常量引用存在的意义是什么啊？？？  
#include <iostream>

using std::cout; using std::endl;


// 常量引用 意思不是  “这个引用是常量” （毕竟引用本身就不是个对象更不能作为常量了）所以说根本就不存在 常量引用 这个东西
void ConstRef(){
    int i = 10;
    double d = 10.5;
    const int ii = 1;
    // int &refii = ii;  非常量引用 不能引用 常量

// 引用的类型必须与其所引用对象的类型一致，but 有两个例外：
//     1---常量引用在初始化时允许绑定一个与其类型不同的对象，只要该对象能够类型转换到常量引用的类型
    const int &consrefdoui = d + 2; 
    /*
        实际上，编译器会这样改变上边这条语句
        const int temp = d;
        const int &consrefdoui = temp;      == 也就是说编译器生成了一个临时量对象，然后把这个临时量与常量引用绑定
    */

    cout << consrefdoui <<endl;     //输出为 12

//     2---允许常量引用绑定  非常量的对象  字面值  一般表达式
    const int &consrefi = i;

    const int &consrefz = 12;
    //int &refi = 12;       显然错误 理由同上

    const int &consrefiexp = i + 2;
    // int &refi = i + 2;   显然错误   非常量引用是要引用到一个对象的
}

// 因为指针本身就是个对象，所以指针可以是常量 所以就会有两个东西---指针常量-常量指针
// 指向const的指针
void PointConst(){
    // const double * --> const double & double
    const double pi = 3.14;
    const double *refPi = &pi;
    // const int *refdoui = &pi; //错误的; 指针const与引用const 不同的一点
    // double *pi = &pi;        // double *  (only-->)  double
   
    double d = 3.15;
    const double *refd = &d;
    // 尝试查看地址:   结果都是一样的地址
    cout << refPi << "  " << &pi <<endl;
    cout << refd << "  " << &d << endl;


    // 所谓指向常量的指针  只规定了不能通过指针改变指向对象的值，but没有规定指向的对象的值能否 **通过其他方式** 改变。
    // 指向const的指针 和  指向的对象  他俩是分离的
}
//  所以说 "对const的引用" 和 "指向const的指针" 都是他们自己'一厢情愿'的以为自己引用或指向了const, 所以他俩都自觉不通过自己来改变引用或指向对象的值


// 指针本身就是个const
void ConstPoint(){

}

// 顶层const 与 底层const  ---  意思就是 const 修饰的是指针 还是 指针所指的对象。
// 比如:    const int *ptr = &i;  可以改变ptr的值，所以这个就是底层const
//          int *const ptr = &i;  为顶层const
//   更普遍的： const int i = 10;  const为顶层const
//          const int *const ptr = &i; 第一个const为底层， 第二个为顶层
//          const int &r 对于引用来说，所有的都是底层const（因为引用本身不是对象啊，也就没有常量的概念）

int GetNum(){
    return 1;
}
constexpr int GetConExp(){
    return 1;
}
// ****  constexpr ****
void constExpr(){
    // 1，值不会改变   2，*** 编译时就可以得到计算结果的 *** 的表达式(特点)
    // example: 字面值就是常量表达式， 用常量表达式初始化的常量对象，也是常量表达式
    int i = 12; // 0
    const int j = 12; // 1 
    const int jj = j + 1; // 1
    const int k =  GetNum();    // 0

    // C11:  constexpr 关键字 : 暂时不知道怎么用？
    // 声明为 constexptr 的变量一定为一常量，且必须由常量表达式来进行

    //字面值类型（不是字面值） 主要有 算数类型（int，double。。） 引用， 指针等
    // 只有字面值类型才可以声明为constexpr
}


void ConstTest(){
    PointConst();
}