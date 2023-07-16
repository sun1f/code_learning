/**
 * @file rvalue.cpp
 * @author elliot (sun1f@foxmail.com)
 * @brief 右值引用与完美转发
 * @version 0.1
 * @date 2023-07-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>

using namespace std;

void otherdef(int& t) {
    cout << "lvalue" << endl;
}

void otherdef(const int& t) {
    cout << "rvalue" << endl;
}

template<typename T>
void func(T&& t) {
    // forward<T>()实现完美转发，完美转发指的是函数模板可以将自己的参数“完美”地转发给内部调用的其它函数。
    // 所谓完美，即不仅能准确地转发参数的值，还能保证被转发参数的左、右值属性不变。
    otherdef(forward<T>(t)); 
    // otherdef(t);  // 这样写，无论传入的形参是左值还是右值，对于函数模板内部来说，形参既有名称又能寻址，因此它都是左值
}

int main()
{
   int n = 10;
   int& num = n;
   
   func(10);
   func(num);


   system("pause");
   return 0;
}
