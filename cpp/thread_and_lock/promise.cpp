#include <thread>
#include <iostream>
#include <future>
using namespace std;

void mythread(std::promise<int> &tmp, int clac)
{
    cout << "mythread() start"
         << "threadid = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    cout << "mythread() end"
         << "threadid = " << std::this_thread::get_id() << endl;
    int result = clac;
    tmp.set_value(result); //结果保存到了tmp这个对象中
    return;
}

// vector<std::packaged_task<int(int)>> task_vec;

int main()
{
    std::promise<int> myprom;
    std::thread t1(mythread, std::ref(myprom), 180);
    t1.join();                                  //在这里线程已经执行完了
    std::future<int> fu1 = myprom.get_future(); // promise和future绑定，用于获取线程返回值
    auto result = fu1.get();
    cout << "result = " << result << endl;
}
