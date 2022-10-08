#include <iostream>
#include <list>
using namespace std;

/***************************
 观察者模式：定义对象间 一对多 的 依赖关系，当一个对象发生了变化，关注它的对象就会得到通知。  
           也称为：发布-订阅（publish-subscribe）

两个角色： 发布者角色， 多个订阅者角色

稳定点： 一对多 的依赖关系
不稳定点：订阅者的个数
**************************/
//抽象订阅者接口
class Observer
{
public:
    virtual void Update(int) = 0;
};

//抽象发布者接口
class Subject
{
public:
    virtual void Attach(Observer *) = 0;
    virtual void Detach(Observer *) = 0;
    virtual void Notify() = 0;
};

//具体的发布者
class ConcreteSubject : public Subject
{
public:
    virtual void Attach(Observer *pObsever)
    {
        m_ObserverList.push_back(pObsever);
    }

    virtual void Detach(Observer *pObsever)
    {
        m_ObserverList.remove(pObsever);
    }

    virtual void Notify()
    {
        std::list<Observer *>::iterator it = m_ObserverList.begin();
        while (it != m_ObserverList.end())
        {
            (*it)->Update(m_iState);
            ++it;
        }
    }

    void setState(int state)
    {
        m_iState = state;
    }

private:
    std::list<Observer *> m_ObserverList;
    int m_iState;
};

//具体订阅者1
class ConcreteObserver1 : public Observer
{
public:
    ConcreteObserver1(Subject *pSubject) : m_pSubject(pSubject) {}
    virtual void Update(int value)
    {
        cout << "ConcreteObserver1 get the update. New State: " << value <<endl;
    }
private:
    Subject *m_pSubject;

};

//具体订阅者2
class ConcreteObserver2 : public Observer
{
public:
    ConcreteObserver2(Subject *pSubject) : m_pSubject(pSubject) {}
    virtual void Update(int value)
    {
        cout << "ConcreteObserver2 get the update. New State: " << value <<endl;
    }
private:
    Subject *m_pSubject;

};
int main()
{
    //发布者实例化
    ConcreteSubject *pSubject = new ConcreteSubject();

    //订阅者实例化
    Observer *pObserver1 = new ConcreteObserver1(pSubject);
    Observer *pObserver2 = new ConcreteObserver2(pSubject);

    //订阅者订阅发布者
    pSubject->Attach(pObserver1);
    pSubject->Attach(pObserver2);

    {
        //发布者状态初始化
        pSubject->setState(2);
        //将初始化状态发布
        pSubject->Notify();
    }
    {
        pSubject->setState(6);
        pSubject->Notify();
    }

    delete pSubject;
    delete pObserver1;
    delete pObserver2;

    return 0;
}