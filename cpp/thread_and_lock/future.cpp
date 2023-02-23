#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <future>

using namespace std;

class A
{
public:
    int my_thread(int my_para)
    {
        cout << "my_thread() start, thread_id is " << this_thread::get_id() << endl;
        chrono::milliseconds dura(5000);
        this_thread::sleep_for(dura);
        cout << "my_thread() end, thread_id is " << this_thread::get_id() << endl;
        return 7;
    }
};

int main()
{
    A a;
    int temp_para = 10;
    cout << "main() start, thread_id is " << this_thread::get_id() << endl;
    future<int> result = async(&A::my_thread, &a, temp_para); //当my_thread是类的成员函数时，，第二个参数是类的对象（引用是为了各线程中直接操作该对象，避免拷贝复制），第三个参数是这个成员函数的参数
    /* future<int> result = async(&A::my_thread, temp_para);如果my_thread不是类的成员函数，第二个参数即为这个成员函数的参数 */
    cout << "continue ... " << endl;
    cout << result.get() << endl;
    // result.get();
    // result.wait();
    cout << "I Love China" << endl;
    /* 异步任务async会使得主线程在准备返回之前，等待该子线程执行完毕，再“return 0;” */
    return 0;
}