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

class Solution
{
public:
    /* struct compare {
        bool operator()(int x, int y) {
            if(ump.count(x)) {
                return ump.count(y) ? ump[x] < ump[y] : true;
            }
            else {
                return ump.count(y) ? false : x < y;
            }
        }
    }; */

    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        for (int i = 0; i < arr2.size(); ++i)
        {
            ump[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y)
             {
            if(ump.count(x)) {
                return ump.count(y) ? ump[x] < ump[y] : true;
            }
            else {
                return ump.count(y) ? false : x < y;
            } });
        return arr1;
    }

private:
    unordered_map<int, int> ump;
};

int main()
{
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
    vector<int> arr2 = {2, 1, 4, 3, 9, 6};

    Solution s;

    vector<int> res;

    res = s.relativeSortArray(arr1, arr2);
    for (int x : res)
    {
        cout << x << ' ';
    }

    // system("pause");
    return 0;
}
