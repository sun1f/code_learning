/**
 * @file tuple.cpp
 * @author elliot (versonpill120@gmail.com)
 * @brief how to use tuple
 * @version 0.1
 * @date 2023-01-26
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <tuple>

using namespace std;

/* template <typename T>
class A
{
private:

public:

}; */

int main()
{
    typedef tuple<int, float, string, vector<int>> t;

    t t1 = {1, 1.1, "china", {1, 2, 3}};
    t t2{2, 2.1, "usa", {2, 5, 0}};
    std::cout << "t.size = " << sizeof(t) << ", t1.size = " << sizeof(t1) << ", t2.size = " << sizeof(t2) << endl;
    std::cout << "t1 = " << get<0>(t1) << ", " << get<1>(t1) << ", " << get<2>(t1) << endl;
    std::cout << "t2 = " << get<0>(t2) << ", " << get<1>(t2) << ", " << get<2>(t2) << endl;

    // system("pause");
    return 0;
}
