#include <thread>
#include <iostream>
#include <future>

#include <pthread.h>
using namespace std;

int mythread(int mypar)
{
    cout << mypar << endl;
    cout << "mythread() start, threadid = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    cout << "mythread() end, threadid = " << std::this_thread::get_id() << endl;
    return 5;
}

void func1()
{
    //我们把函数mythread通过packaged_task包装起来
    //参数是一个int，返回值类型是int
    std::packaged_task<int(int)> mypt1(mythread);
    std::thread t1(ref(mypt1), 1);
    t1.join();
    std::future<int> result = mypt1.get_future();
    // std::future对象里包含有线程入口函数的返回结果，这里result保存mythread返回的结果。
    cout << result.get() << endl;
    return;
}

void func2()
{
    std::packaged_task<int(int)> mypt2([](int mypar)
                                       {
        cout << mypar << endl;
        cout << "mythread() start, threadid = " << std::this_thread::get_id() << endl;
        std::chrono::milliseconds dura(5000);
        std::this_thread::sleep_for(dura);
        cout << "mythread() end, threadid = " << std::this_thread::get_id() << endl;
        return 5; });

    std::thread t2(ref(mypt2), 19);
    t2.join();
    std::future<int> result = mypt2.get_future();
    // std::future对象里包含有线程入口函数的返回结果，这里result保存mythread返回的结果。

    cout << result.get() << endl;
    cout << "good luck" << endl;
    return;
}

int main()
{
    cout << "main, threadid = " << std::this_thread::get_id() << endl;
    func1();
    cout << "fun1() is finished, and func2() is begining... " << endl;
    func2();
    /* 为什么func1()和func2()创建的是同一个线程 */
    return 0;
}
