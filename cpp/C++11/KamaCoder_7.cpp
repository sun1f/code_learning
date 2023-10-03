#include <iostream>
using namespace std;

int main()
{
    char x;
    string s;
    while (1)
    {
        cin >> x;
        if (cin.get() == '\n')
            break;
        if(cin.get() == ' ')
            continue;
        s.push_back(x);
    }
    int ans = 0;
    for (char c : s)
    {
        if (c == 'A')
            ans += 4;
        else if (c == 'B')
            ans += 3;
        else if (c == 'C')
            ans += 2;
        else if (c == 'D')
            ans += 1;
        else if (c == 'F')
            ans += 0;
        else {
            cout << "Unknown" << endl;
            return 0;
        }
    }
    cout << (double)ans / s.size() << endl;
    return 0;
}