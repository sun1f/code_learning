#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <functional>

using namespace std;

/* template <typename T>
class A
{
private:

public:

}; */

vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k)
{
    unordered_map<int, unordered_set<int>> activeMinutes;
    for (auto &&log : logs)
    {
        int id = log[0], time = log[1];
        // activeMinutes[id].emplace(time);
        activeMinutes[id] = unordered_set<int>{time};
    }
    vector<int> answer(k);
    for (auto &&[_, minutes] : activeMinutes)
    {
        int activeCount = minutes.size();
        answer[activeCount - 1]++;
    }
    return answer;
}
void print_v(vector<int> res)
{
    for (int x : res)
        cout << x << ' ';
}
int main()
{
    vector<vector<int>> logs = {{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}};
    int k = 5;
    vector<int> res = findingUsersActiveMinutes(logs, k);
    for (int x : res)
        cout << x << ' ';
    cout << endl;
    vector<int> v = vector<int>(9, 8);
    print_v(v);
    // system("pause");
    return 0;
}
