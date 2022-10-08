#include "include_once.h"
#include <iostream>
#include <tuple>
using namespace std;
int main()
{
    //元组可以有结构体的特征，简洁直观
    //创建元组方式
    tuple<const char*, int> tu = make_tuple("first", 5);
    cout << typeid(tu).name() << endl;
    
    //获取元素方式1
    const char* data = std::get<0>(tu);
    int len = std::get<1>(tu);
    cout << "data= " << data << "  len= "<< len << endl;
    //获取元素方式2
    const char* data1 = nullptr;
    int len1 = -1;
    std::tie(data1, len1) = tu;
    cout << "data1= " << data1 << "  len1= " << len1 << endl;
    return 0;
}