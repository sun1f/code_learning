/**
 * @file 20230118.cpp
 * @author elliot (versonpill120@gmail.com)
 * @brief C++多态性
 * @version 0.1
 * @date 2023-01-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;
/* 1. 不加virtual，派生类和基类的“同名同形参同const且返回值兼容（向上转型）”函数会直接被派生类覆盖，但是用派生类对象地址初始化的基类指针只能访问基类中的该同名函数
   2. 不加virtual情况下，派生类和基类“同名但不完全同形参或const或返回值兼容”函数由派生类对象调用基类该函数时需要加双冒号限定或使用基类指针
   3. override关键字只能对虚函数使用，对同名的非虚函数在派生类加override会报错*/
class Basic
{
public:
    // Basic(){};
    Basic(int b) : m_b(b){};
    void display() const;
    /* 纯虚函数写作 virtual void func(float f) = 0;
    包含纯虚函数的类叫做抽象类，抽象类不能定义对象，但可以定义用派生类对象初始化的抽象类指针 */
    virtual void func(float f) const = 0;
    virtual int bb(int a) { return 1; };
    int love(int a) { return a; };
    /* final只能作用于虚函数 */
    virtual void fin(int a) final {}

private:
    int m_b;
};
class D : public Basic
{
public:
    D(int d) : m_d(d), Basic(9){};
    void display_D() const;
    virtual void func(float f) const override;
    int bb(int a) { return 0; };
    int love(char c) { return 0; }
    virtual void fin(double a) final {}


private:
    int m_d;
};
void Basic::func(float f) const { cout << "func in Basic, f = " << f << endl; }
void D::func(float f) const { cout << "func in D, f = " << f << endl; }
void Basic::display() const
{
    cout << "Basic display function..."
         << "m_b = " << m_b << endl;
}
void D::display_D() const
{
    cout << "D display_d function..."
         << "m_d = " << m_d << endl;
}

int main()
{
    Basic *b = new D(1);
    b->display();
    D *d = new D(3);
    d->display_D();
    cout << "-----------" << endl;
    b->func(1.9);
    d->func(2.0);
    cout << "-----------" << endl;
    cout << b->bb(1) << endl;
    cout << d->bb(1) << endl;
    cout << "-----------" << endl;
    D dre(11);
    cout << dre.Basic::love(9);
    // system("pause");
    return 0;
}
