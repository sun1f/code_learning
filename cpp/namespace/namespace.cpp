#include <iostream>
#include <vector>
using namespace std;

namespace sp1
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6};
    void t1()
    {
        for (auto i : v1)
        {
            cout << i << " ";
        }
        for (int i = 0; i < 3; ++i)
        {
            v1[i] = static_cast<int>(NULL);
        }
        cout << "---------------" << endl;
        for (auto i : v1)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    sp1::t1();
    return 0;
}