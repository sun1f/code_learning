/**
 * @file explicit.cpp
 * @author elliot (versonpill120@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-01-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
using namespace std;

class A
{
};

class B
{
public:
    B(){}
    // conversion from A (constructor):
    /*B(const A &x)
    {
        std::cout << "B's constructor" << std::endl;
    }*/

    // conversion from A (assignment):
    B &operator=(const A &x)
    {
        std::cout << "B's assignment" << std::endl;
        return *this;
    }

    // conversion to A (type-cast operator)
    operator A()
    {
        std::cout << "B's conversion" << std::endl;
        return A();
    }
};

void fn(B arg)
{
    std::cout << "function" << std::endl;
}

int main()
{
    A foo;
    //B bar(foo);
    B b;
    b = foo;
    // B bar = foo;    // calls constructor, 添加explicit出错, 不能默认构造
    // bar = foo;      // calls assignment
    // foo = bar;      // calls type-cast operator

    // fn(foo); //添加explicit出错, 就不能默认的隐式转换
    //fn(bar);

    return 0;
}
