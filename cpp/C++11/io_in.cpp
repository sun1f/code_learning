#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
// 使用stringstream需要头文件<sstream>
#include <sstream>

using namespace std;

void test1()
{
    char ch;
    while ((ch = cin.get()) != EOF)
        cout.put(ch);
}
void test2()
{
    string line;
    ifstream in;
    in.open("io.txt");
    getline(in, line, '\t');
    cout << "line = " << line << endl;
    in.close();
}

// 用istringstream将字符串转换成其他类型数据
template <typename T>
inline T fromstring(const string &str)
{
    istringstream is(str); // 创建字符串输入流
    T v;
    is >> v;
    return v;
}

int main()
{
    // test1();
    // test2();
    int i1 = fromstring<int>("78878");
    float f1 = fromstring<float>("1.89849");
    cout << "i1 = " << i1 << endl
         << "f1 = " << f1 << endl;
    // system("pause");
    return 0;
}
