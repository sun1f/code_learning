#include <iostream>
#include <vector>


using namespace std;

bool isvalid(vector<int> &course, vector<int> &score, int target)
{
    int sum = 0, res = 0;
    int sum_course = 0;
    for (int i = 0; i < course.size(); ++i)
    {
        sum += score[i] * course[i];
        sum_course += course[i];
    }
    res = sum / sum_course;
    return res >= target;
}

int main()
{
    int T, n, X;
    vector<int> course;
    vector<int> score;
    int num;
    cin >> T;
    int tmp = T;
    while (tmp--)
    {
        cin >> n >> X;
        while (cin.get() != '\n')
        {
            cin >> num;
            course.push_back(num);
        }
        while (cin.get() != '\n')
        {
            cin >> num;
            score.push_back(num);
        }
        if (!isvalid(course, score, X))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
