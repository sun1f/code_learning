#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T1, typename T2>
class A
{
private:
public:
    A() { cout << "class A<T1, T2> "; }
};
template <typename T2>
class A<bool, T2>
{
private:
public:
    A() { cout << "class A<bool, T2> "; }
};

int main()
{
    //A<int, int> a;
    A<bool, vector<int>> aa;
    // system("pause");
    return 0;
}
