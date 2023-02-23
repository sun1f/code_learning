#include <thread>
#include <iostream>
#include <future>
using namespace std;

int mythread(int mypar)
{
    cout << "mythread() start, thread_id = " << this_thread::get_id() << endl;
    chrono::milliseconds dura(5000);
    this_thread::sleep_for(dura);
    return 5;
}

void mythread2(future<int> &tmpf)
{
    cout << "mythread2() start, thread_id = " << this_thread::get_id() << endl;
    auto result = tmpf.get();
    cout << "mythread2 result = " << result << endl;
    return;
}
int main()
{
    cout << "main, thread_id = " << this_thread::get_id() << endl;
    packaged_task<int(int)> mypt(mythread);
    thread t1(ref(mypt), 1);
    t1.join();

    future<int> result = mypt.get_future();
    thread t2(mythread2, ref(result));
    t2.join();

    cout << "I Love China!" << endl;

    return 0;
}