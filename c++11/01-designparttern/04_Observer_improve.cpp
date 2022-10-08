#include <iostream>
#include <string>
#include <functional>
#include <map>

using std::cout;
using std::endl;
using std::string;
using std::map;

/********************************
 普通观察者模式存在以下缺陷：
 1、需要继承，耦合性高
 2、观察者被通知的接口参数不支持变化，导致观察者不能应付接口的变化，并且观察者还不能带参数

 改进的观察者模式：（使用c++11）
    1、通过被通知接口参数化 和 std::function 来代替继承
    2、通过可变参数模板 和 完美转发 来消除接口变化产生的影响
    具体改进：
        1、使用delete操作符屏蔽 拷贝构造函数 和 赋值操作符，使events对象不能拷贝和赋值
        2、使用map保存观察者（发布者）事件列表
        3、使用自增成员变量保存观察者事件key
        4、使用可变模板参数屏蔽函数参数变动
 ********************************/
class NonCopyable
{
public:
    NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

//观察者（发布者）事件
template <typename Func>
class Events : public NonCopyable
{
public:
    //注册观察者，支持右值引用
    int Connect(Func&& f)
    {
        return Assign(f);
    }

    //注册观察者，左值
    int Connect(const Func &f)
    {
        return Assign(f);
    }

    //移除观察者
    void DIscinnect(int key)
    {
        m_connections.erase(key);
    }
    
    //通知所有观察者
    template <typename ...Args>
    void Notify(Args&& ... args)
    {
        for(auto &it : m_connections)
        {
            auto& func = it.second;
            func(std::forward<Args>(args)...);
        }
    }

private:
    template <typename F>
    int Assign(F&& f)
    {
        int k = m_observerId++;
        m_connections.emplace(k,std::forward<F>(f));
        return k;
    }

    int m_observerId = 0;            // 观察者对应编号
    map<int, Func> m_connections;    // 观察者列表
};

using ObserverFunc = std::function<int(int, int)>;
class Observer1
{
public:
    int operator()(int a, int b)
    {
        cout << "Observer1函数对象的事件2被调用" <<endl;
        int res = a + b;
        return res;
    }
};

class Observer2
{
public:
    int observerFunc(int a, int b)
    {
        cout << "Observer2成员函数  事件3被调用" <<endl;
        int res = a + b;
        return res;
    }
};

int gobserverFunc(int a, int b)
{
        cout << "全局的gobserverFunc事件4被调用" <<endl;
        int res = a + b;
        return res;
}


int main()
{
    Events<ObserverFunc> e;

    // 调lambda表达式的观察者函数
    int lambdaID = e.Connect([](int a, int b){
        int res = a + b;
        cout << "lambda函数         事件1被调用" << endl;
        return res;
        });

    // 调用仿函数的观察者函数
    int obsID1 = e.Connect(Observer1());

    // 调用成员函数的观察者函数
    Observer2 o2;
    int obsID2 = e.Connect(std::bind(&Observer2::observerFunc, o2, std::placeholders::_1, std::placeholders::_2));

    // 调用全局观察者函数
    int gID4 = e.Connect(gobserverFunc);

    e.Notify(1, 2);

    return 0;
}
