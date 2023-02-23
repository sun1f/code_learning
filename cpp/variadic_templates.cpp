#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>

using namespace std;

void print() {}

template <typename T, typename... Types>
void print(const T &firstarg, const Types &...args)
{
    cout << firstarg << endl;
    print(args...);
}

int main()
{
    print<int, double, string>(1, 2.6, "syf");
    print("suhsu", 's', 788, 90.09);
    print("only one");
    // system("pause");
    return 0;
}
