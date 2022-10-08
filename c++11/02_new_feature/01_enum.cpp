#include "include_once.h"
#include <iostream>
#include <vector>
using namespace std;

//three points of concern for c++11
//1、action scope restrict

enum class DAY{      //have restrict

    MONDAY, TUESDAY, WEDNEDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

enum MONNTH{
    JANUARY, FEBRUARY, MARCH, APRIL, JUNNE, JULLY, AUGUST, AEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

//2、the type of element
enum class DAY1 : uint8_t{      //have restrict

    MONDAY, TUESDAY, WEDNEDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY
};

//2、no complicit conversion

int main()
{
    cout << "have restrict" << endl;
    cout << "sizeof(DAY::FRIDAY):"<< sizeof(DAY::FRIDAY) << endl;
    cout << typeid(0.999).name() << endl;

    cout << "have no restrict" << endl;
    cout << JANUARY << endl;

    cout << "the type of element" << endl;
    cout << "sizeof(DAY1::FRIDAY):"<< sizeof(DAY1::FRIDAY) << endl;

    vector<int> tc(10, 3);
    tc.reserve(30);
    tc.push_back(222);
    cout<<"size:"<<tc.size()<<"  capacity:"<<tc.capacity()<<endl;
    for(auto i : tc)
        cout << i<<endl;
    tc.clear();
    tc.push_back(99);
    cout<<"size:"<<tc.size()<<"  capacity:"<<tc.capacity()<<endl;
    for(auto i : tc)
        cout << i<<endl;
    return 0;
}