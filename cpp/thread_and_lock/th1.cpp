#include <iostream>
#include <thread>
#include <string>

using namespace std;

void myprint1()
{
    cout << "myprint线程开始执行" << endl;
}

class A
{
public:
    A(int i) : m_i(i) { cout << "A(int i)构造函数执行, thread_id = " << this_thread::get_id() << endl; }
    A(const A &a) : m_i(a.m_i) { cout << "A(const A &a)拷贝构造函数执行, thread_id = " << this_thread::get_id() << endl; }

    ~A() { cout << "~A()A的析构函数执行, thread_id = " << this_thread::get_id() << endl; }

private:
    int m_i;
};

void myprint2(const A &aa)
{
    cout << "子线程myprint2()开始执行, thread_id = " << this_thread::get_id() << endl;
    ;
}

int main()
{
    int pa = 8;
    thread th1(myprint2, A(pa)); /* 如果写thread th1(myprint2,pa)，类A的对象在子线程中构造，如果主线程先执行完，pa被回收掉就会出现错误 */
    /* 而A(pa)这种写法构造类A的临时对象，是在主线程中完成，所以在主线程执行完毕时一定已经构造完成了，把这个对象传给子线程一定不会出错 */
    th1.detach();

    cout << "主线程执行, thread_id = " << this_thread::get_id() << endl;

    return 0;
}
/* int main()
{
    thread th1(myprint);
    if (th1.joinable())
    {
        cout << "1.joinable() == true" << endl;
    }
    else
    {
        cout << "1.joinable() == false" << endl;
    }
    th1.join(); //阻塞主线程，等待子线程myprint()执行完

    if (th1.joinable())
    {
        cout << "1.joinable() == true" << endl;
    }
    else
    {
        cout << "1.joinable() == false" << endl;
    }
    cout << "I love China!" << endl;

    string s;
    char buffer[] = "i love china ";
    s = buffer;
    const char *ch = s.c_str();
    cout << "s.c_str()= " << s.c_str() << "sizeof(s.c_str())= " << sizeof(s.c_str()) << endl;
    cout << "s.data()= " << s.data() << "sizeof(s.data())= " << sizeof(s.data()) << endl;
    cout << "thread_id = " << this_thread::get_id() << endl;
    return 0;
} */