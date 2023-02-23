/**
 * @file lower_bound.cpp
 * @author elliot (versonpill120@gmail.com)
 * @brief the use of function lower_bound
 * @version 0.1
 * @date 2023-01-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef struct Student
{
    int _id;
    int _num;

    Student(int id, int num)
        : _id(id), _num(num)
    {
    }

} Stu;

struct CompareV
{
    bool operator()(const Stu &s1, const Stu &s2) //  排名升序
    {
        return s1._num < s2._num;
    }
};

int main()
{
    vector<Stu> vS = {{101, 34}, {103, 39}, {102, 35}, {109, 67}};
    sort(vS.begin(), vS.end(), CompareV());

    // CompareV()排完序后是这个丫子
    // 101 34
    // 102 35
    // 103 39
    // 109 67
    auto iter = lower_bound(vS.begin(), vS.end(), Stu(200, 36), CompareV());
    cout << iter - vS.begin() << endl
         << (*iter)._id << endl; // 我们就找到了按仿函数排序(找排名比33大的位置 就是0）
    // system("pause");

    return 0;
}