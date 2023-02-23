#include <iostream>
#include <string>
using namespace std;
class data1
{
private:
    int id;
public:
    data1(int ID) : id(ID) {};
    data1() {};
    friend ostream &operator<<(ostream &out, data1 &a);
};
ostream &operator<<(ostream &out, data1 &a)
{
    cout << "hello operator << and id is " << a.id << endl;
}
int main()
{
    string s = "12345";
    s.insert(s.begin() + 2, '&');
    for(auto& x : s)
        cout << x << endl;
    data1 A(187);
    data1 A1(1890);
    // A << cout;
    cout << A << A1;
    return 0;
}
