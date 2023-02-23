#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int howmanytimes(string num, char c)
{
    int count = 0;
    for (char x : num)
    {
        if (x == c)
            count++;
    }
    return count;
}
bool digitCount(string num)
{
    for (int i = 0; i < num.size(); ++i)
    {
        if (howmanytimes(num, i + '0') != num[i])
            return false;
    }
    return true;
}

int main() {
    string s = "121000000000000000000000";
    cout << digitCount(s);
}