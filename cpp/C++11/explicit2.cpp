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

class Point
{
public:
    int m_x, m_y;
    explicit Point(int x = 0, int y = 0)
        : m_x(x), m_y(y) { cout << "construct" << endl; }
    Point &operator()(int x, int y)
    {
        m_x = x * 10;
        m_y = y * 10;
        cout << "operator()" << endl;
        return *this;
    }
};

void displayPoint(const Point &p)
{
    cout << "(" << p.m_x << ","
         << p.m_y << ")" << endl;
}

int main()
{
    displayPoint(Point(1, 4));
    // 只有第一遍时执行构造函数，之后再调用()执行的都是operator()函数
    Point p(1, 2);
    displayPoint(p(1, 2));
    // displayPoint();
    //  displayPoint(1);
    //  displayPoint(Point());

    // system("pause");
    return 0;
}
