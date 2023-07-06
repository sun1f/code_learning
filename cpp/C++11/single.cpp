#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

/* 单例模式：
    v1是有缺陷的懒汉模式，存在线程安全与内存泄漏的问题；
    v2使用智能指针shared_ptr，是线程安全，内存安全的懒汉模式
    v3是局部静态变量的懒汉模式（最好，C++11以上）
    v4是饿汉模式，在程序入口前完成单例对象的初始化
 */

class Single_v1
{
private:
    ~Single_v1()
    {
        cout << "destorctive function called." << endl;
    }
    Single_v1(const Single_v1 &) = delete;
    const Single_v1 operator=(const Single_v1 &) = delete;
    static Single_v1 *m_single_v1;

public:
    Single_v1()
    {
        cout << "constructive function called." << endl;
    }
    static Single_v1 *Instance()
    {
        if (m_single_v1 == nullptr)
        {
            m_single_v1 = new Single_v1();
        }
        return m_single_v1;
    }
};
/* 初始化static变量 */
Single_v1 *Single_v1::m_single_v1 = nullptr;

class Single_v2
{
public:
    ~Single_v2()
    {
        cout << "destorctive function called." << endl;
    }
    Single_v2(const Single_v2 &) = delete;
    const Single_v2 &operator=(const Single_v2 &) = delete;
    static shared_ptr<Single_v2> Instance()
    {
        if (m_single_v2 == nullptr)
        {
            lock_guard<mutex> lk(m_mutex);
            if (m_single_v2 == nullptr)
            {
                m_single_v2 = shared_ptr<Single_v2>(new Single_v2());
            }
        }
        return m_single_v2;
    }

private:
    Single_v2()
    {
        cout << "constructive function called." << endl;
    }
    static shared_ptr<Single_v2> m_single_v2;
    static mutex m_mutex;
};
/* 初始化static变量 */
shared_ptr<Single_v2> Single_v2::m_single_v2 = nullptr;
mutex Single_v2::m_mutex;

class Single_v3
{
public:
    static Single_v3 &Instance()
    {
        static Single_v3 m_Instance;
        return m_Instance;
    }

private:
    Single_v3()
    {
        cout << "constructive function v3 called." << endl;
    }
    Single_v3(const Single_v3 &) = delete;
    const Single_v3 &operator=(const Single_v3 &) = delete;
    ~Single_v3()
    {
        cout << "destorctive function v3 called." << endl;
    }
};

class Single_v4
{
public:
    ~Single_v4()
    {
        cout << "destorctive function called." << endl;
    }
    static shared_ptr<Single_v4> Instance()
    {
        if (m_Instance == nullptr)
        {
            m_Instance = shared_ptr<Single_v4>(new Single_v4());
            return m_Instance;
        }
        return m_Instance;
    }

    shared_ptr<Single_v4> getInstance()
    {
        cout << "getInstance" << endl;
        return m_Instance;
    }

private:
    Single_v4()
    {
        cout << "constructive function v4 called." << endl;
    }
    Single_v4(const Single_v4 &) = delete;
    const Single_v4 &operator=(const Single_v4 &) = delete;

    static shared_ptr<Single_v4> m_Instance;
};
shared_ptr<Single_v4> Single_v4::m_Instance = Single_v4::Instance();

int main()
{
    /* Single_v1 *p1 = Single_v1::Instance();
    Single_v1 *p2 = Single_v1::Instance(); */

    /* shared_ptr<Single_v2> p3 = Single_v2::Instance(); */

    Single_v3 &p4 = Single_v3::Instance();
    Single_v3 &p5 = Single_v3::Instance();

    /* shared_ptr<Single_v4> p6;
    p6->getInstance(); */
    return 0;
}
