#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

long long countFairPairs(vector<int> &nums, int lower, int upper)
{
    long long count = 0;
    unordered_map<int, int> ump;
    for (auto &x : nums)
        ump[x]++;
    vector<pair<int, int>> v;
    for (auto it : ump)
    {
        v.push_back(it);
    }
    if (v.size() == 1)
    {
        if (v[0] >= lower && v[0] <= upper && 2 * v[0] >= lower && 2 * v[0] <= upper)
            return v[0].second * (v[0].second - 1) / 2;
        else if (!(v[0] >= lower && v[0] <= upper))
            return 0;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        for (int j = i + 1; j < v.size(); ++j)
        {
            if (v[i].first + v[j].first >= lower && v[i].first + v[j].first <= upper)
                count += v[i].second * v[j].second;
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int count = countFairPairs(nums, 3, 6);
    cout << count;
}