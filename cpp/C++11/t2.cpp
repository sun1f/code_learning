#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> &s1, vector<int> &s2, vector<vector<int>> &dice, int n, int sum)
{
    if (s1.empty() && s2.empty())
    {
        int target = sum / (n / 2);
        for (int i = 0; i < n; ++i)
        {
            int j = (i + n / 2) % n;
            if (dice[i][j] + dice[j][i] != target)
                return false;
        }
        return true;
    }
    for (int i = 0; i < s1.size(); ++i)
    {
        int x = s1[i];
        for (int j = 0; j < s2.size(); ++j)
        {
            int y = s2[j];
            if (x + y == sum / (n / 2))
            {
                int pos1 = n - s1.size() + i;
                int pos2 = n - s2.size() + j;
                dice[pos1][pos2] = x;
                dice[pos2][pos1] = y;
                s1.erase(s1.begin() + i);
                s2.erase(s2.begin() + j);

                if (dfs(s1, s2, dice, n, sum))
                    return true;
                dice[pos1][pos2] = 0;
                dice[pos2][pos1] = 0;
                s1.insert(s1.begin() + i, x);
                s2.insert(s2.begin() + j, y);
            }
        }
    }
    return false;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> s1(n / 2);
        vector<int> s2(n / 2);
        int sum = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            cin >> s1[i];
            sum += s1[i];
        }
        for (int i = 0; i < n / 2; ++i)
        {
            cin >> s2[i];
            sum += s2[i];
        }
        vector<vector<int>> dice(n, vector<int>(n));
        if ((dfs(s1, s2, dice, n, sum)))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
