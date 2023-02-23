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
public:
    A(int a) : m_a(a) { cout << "A(int a)"; };
    // A() { cout << "A()"; };
    A() = default;

private:
    int m_a;
};
int main()
{
    A a1(2);
    A a2;

    // system("pause");
    return 0;
}
