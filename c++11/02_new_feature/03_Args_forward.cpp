#include <iostream>
using namespace std;

/****************************
1、模板中的&&不代表右值引用，而是“万能引用“，其既能接收左值 也能接受右值
2、完美转发：通过一个中转函数原封不动的将参数传递给另一个函数，即不改变引用属性
 * **************************/

/********************* 1、完美引用**************************/
void Fun(int& x) {cout << "左值引用" << endl;}
void Fun(const int& x) {cout << "const左值引用" << endl;}
void Fun(int&& x) {cout << "右值引用" << endl;}
void Fun(const int&& x) {cout << "const右值引用" << endl;}
template <typename T>
void Perfect(T&& t)
{
    //Fun(t);                  // result1;
    Fun(std::forward<T>(t));   //result2
}
void test1()
{
    Perfect(1);     //传右值

    int a = 5;
    Perfect(a);     //传左值

    Perfect(std::move(a));   //传右值

    const int b = 10;
    Perfect(b);              //传const左值

    Perfect(std::move(b));   //传const右值

    /*result1:
     左值引用
     左值引用
     左值引用
     const左值引用
     const左值引用
    ========》推测出：右值在传参时丢失了右值属性，变成了左值。（故有完美转发std::forward解决）
    ========》原因：右值不可以取地址，左值可以；右值在传参的时候被保存到了特定的位置，所以就可以取地址了，失去了右值属性
    */

   /*result2:
    右值引用
    左值引用
    右值引用
    const左值引用
    const右值引用
   */  
}
/*************************************************************/

/*************************模板可变参数**************************/
void FunctionArg() {cout << endl;}

template <class T, class ...Args>
void FunctionArg(T value, Args... args)
{
    cout << "参数个数为： " << sizeof...(args) << endl;
    cout << value << endl;
    FunctionArg(args...);
}

template <class ...Args>
void Function(Args... args)
{
    FunctionArg(args...);
}

void test2()
{
    Function(std::string("sort"), 1, 'A');
    Function(1, 3, 2.34);
}
int main()
{
    //test1();
    test2();




    return 0;
}