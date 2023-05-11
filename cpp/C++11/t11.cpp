#include <iostream>
#include <vector>
using namespace std;

bool isvalid(int n, int x, vector<int> &credits, vector<int> &scores)
{
    int total_credits = 0;
    int total_weighted_score = 0;
    int min_score = 60;

    for (int i = 0; i < n; ++i)
    {
        total_credits += credits[i];
        total_weighted_score += credits[i] * scores[i];
        if (scores[i] < min_score)
            return false;
    }

    double agv_score = (double)total_weighted_score / total_credits;
    if (agv_score >= x)
        return true;
    else
        return false;
}
int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, x;
        cin >> n >> x;
        vector<int> credits(n);
        vector<int> scores(n);

        for (int j = 0; j < n; ++j)
        {
            cin >> credits[j];
        }
        for (int j = 0; j < n; ++j)
        {
            cin >> scores[j];
        }

        if (isvalid(n, x, credits, scores))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
