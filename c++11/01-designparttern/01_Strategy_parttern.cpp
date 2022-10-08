#include <iostream>
using namespace std;

/*************************************
策略模式：定义了一系列的算法，并将每一个算法封装起来，而且使它们还可以互相替换。
策略模式让算法独立于使用它的客户而独立变化

三个角色：抽象的算法接口角色，具体的算法接口角色，调用算法的角色

稳定点：程序调用算法的方式
变化点：算法的种类
***************************************/

//武器策略：抽象武器基类角色，让各类武器算法继承于此
class weaponStrategy
{
public:
    virtual void useweaponStrategy() = 0;
};


//小刀武器算法角色1
class Knife : public weaponStrategy
{
public:
    virtual void useweaponStrategy()
    {
        cout << "使用小刀算法" << endl;
    }
};
//AK47武器算法角色2
class AK47 : public weaponStrategy
{
public:
    virtual void useweaponStrategy()
    {
        cout << "使用AK47算法" << endl;
    }
};


//策略调用者角色
class Character
{
public:
    void setWeapon(weaponStrategy *weapon)
    {
        this->pweapon = weapon;
    }
    void throwWeapon()
    {
        this->pweapon->useweaponStrategy();
    }
    weaponStrategy *pweapon;
};
int main()
{
    //调用着角色
    Character *character = new Character;
    //算法角色1
    weaponStrategy *knife = new Knife;
    weaponStrategy *ak47 = new AK47;
    character->setWeapon(knife);
    character->throwWeapon();

    character->setWeapon(ak47);
    character->throwWeapon();
    cout << "normal!" << endl;

    delete character;
    delete knife;
    delete ak47;
    
    return 0;
}