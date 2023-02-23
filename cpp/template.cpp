#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 结构体struct默认public，class默认private
struct people
{
    int id;
    string name;
    double gpa;
};
class student
{
public:
    student(){};
    student(int a, double b) : id(a), gpa(b){};
    friend ostream &operator<<(ostream &out, const student &s);

private:
    int id;
    double gpa;
};

ostream &operator<<(ostream &out, const student &s)
{
    out << "id = " << s.id << " and gpa = " << s.gpa << endl;
    return out;
}

template <typename T>
class store
{
public:
    store();
    friend T;
    void putitem(const T &x);
    void getitem();

private:
    vector<T> item;
    bool havevalue;
};

template <typename T>
store<T>::store() : havevalue(false){};
template <typename T>
void store<T>::putitem(const T &x)
{
    item.push_back(x);
    havevalue = true;
}
template <typename T>
void store<T>::getitem()
{
    if (!havevalue)
    {
        cout << "No item present" << endl;
        exit(1);
    }
    else
    {
        for (auto &it : item)
            cout << it << endl;
    }
}

int main()
{
    // 如何初始化结构体对象
    people p1 = {1, "syf", 100.0};
    cout << "p1.id = " << p1.id << ", p1.name = " << p1.name << ", p1.gpa = " << p1.gpa << endl;
    student s1(1, 3.4);
    student s2(6, 4.0);
    student s3(7, 2.7);
    student s4(8, 3.3);
    student s5(9, 1.6);
    using store_student = store<student>;
    store_student st;
    st.putitem(s1);
    st.putitem(s2);
    st.putitem(s3);
    st.putitem(s4);
    st.putitem(s5);
    st.getitem();
    // system("pause");
    return 0;
}
