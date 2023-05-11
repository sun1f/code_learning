#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    const int N = 100000;
    int n;
    char s[N];
    int left[N], right[N];

    cin >> n;
    cin >> s + 1;

    left[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (s[i] == '1')
            left[i] = left[i - 1] + 1;
        else
            left[i] = left[i - 1];
    }

    right[n - 1] = 0;
    for (int i = n - 2; i >= 0; --i)
    {
        if (s[i + 1] == '0')
            right[i] = right[i + 1] + 1;
        else
            right[i] = right[i + 1];
    }

    int ans = n;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i; j <= n; ++j)
            ans = min(ans, left[i] + right[j] + j - i - left[j] + right[i]);
    }
    cout << ans << endl;
    return 0;
}