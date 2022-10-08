#include <iostream>

using namespace std;

/**********************************
模板方法模式：将算法骨架定义好后，骨架中的部分在父类中进行实现，而子类的个性化行为则由子类继承父类再加以实现。

两个角色：父类骨架角色，子类算法角色

稳定点：算法骨架
变化点：子类个性化算法
************************************/

//抽象类，父类骨架角色
class BaseClass
{
public:
    BaseClass(){}
    ~BaseClass(){}

    //算法骨架
    void ExcutesSequence()
    {
        this->BrushTeeth();
        this->Eat();
    }
    virtual void BrushTeeth() = 0;
    virtual void Eat() = 0;
};


//具体执行过程A，子类算法角色
class MethodA : public BaseClass
{
public:
    MethodA(){}
    ~MethodA(){}
    virtual void BrushTeeth()
    {
        cout << "用电动牙刷刷牙后" << endl;
    }
    virtual void Eat()
    {
        cout << "吃西瓜" << endl;
    }
};
//具体执行过程B，子类算法角色
class MethodB : public BaseClass
{
public:
    MethodB(){}
    ~MethodB(){}
    virtual void BrushTeeth()
    {
        cout << "用普通牙刷刷牙后" << endl;
    }
    virtual void Eat()
    {
        cout << "吃葡萄" << endl;
    }
};

int main()
{
    BaseClass *PBase = new MethodA();
    PBase -> ExcutesSequence();

    PBase = new MethodB();
    PBase -> ExcutesSequence();

    delete PBase;

    return 0;
}