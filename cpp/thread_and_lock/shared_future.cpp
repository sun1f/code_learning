#include <thread>
#include <iostream>
#include <future>
using namespace std;

int mythread()
{
    cout << "mythread() start"
         << "threadid = " << std::this_thread::get_id() << endl;
    std::chrono::milliseconds dura(5000);
    std::this_thread::sleep_for(dura);
    cout << "mythread() end"
         << "threadid = " << std::this_thread::get_id() << endl;
    return 5;
}

int main()
{
    cout << "main"
         << "threadid = " << std::this_thread::get_id() << endl;
    std::packaged_task<int()> mypt(mythread);
    std::thread t1(std::ref(mypt));
    std::future<int> result = mypt.get_future();

    bool ifcanget = result.valid();                   //判断future中的值是不是一个有效值
    std::shared_future<int> result_s(result.share()); //执行完毕后result_s里有值，而result里空了
                                                      // std::shared_future<int> result_s(std::move(result));
    //通过get_future返回值直接构造一个shared_future对象
    // std::shared_future<int> result_s(mypt.get_future());
    t1.join();

    auto myresult1 = result_s.get();
    auto myresult2 = result_s.get();

    cout << "good luck" << endl;
    return 0;
}
