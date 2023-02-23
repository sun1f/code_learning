#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

/* template <typename T>
class A
{
private:

public:

}; */
class A
{
private:
    int m_a;

public:
    A() = delete;
    A(int a);
};
A::A(int a) : m_a(a)
{
    {
        cout << "A(int a) " << m_a;
    };
}
int main()
{
    A a(9);
    // system("pause");
    return 0;
}
