#include <iostream>
#include <thread>
#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

class A
{
public:
    void inmes()
    {
        for (int i = 0; i < 100; ++i)
        {
            cout << "A:inmes() begins to work" << endl;
            unique_lock<mutex> sbguard(mu1);

            chrono::milliseconds dura(20);
            this_thread::sleep_for(dura);

            mesque.push_back(i);

            my_cond.notify_one();
            cout << "i= " << i << endl;
        }
        return;
    }
    bool outlolmes()
    {
        while (command < 99)
        {
            unique_lock<mutex> sbguard(mu1);
            //一个lambda表达式就是一个可调用对象
            my_cond.wait(sbguard, [this]
                         {
            if(!mesque.empty())
            return true;
            else{
            cout << "mesque is empty!" << endl;
            return false; } });

            command = mesque.front();
            mesque.pop_front();
            sbguard.unlock();
            cout << "outlolmes()执行，取出一个元素" << command << endl;
        }
        return false;
    }

    void outmes()
    {
        for (int i = 0; i < 100; ++i)
        {
            if (!outlolmes())
            {
                // do nothing
            }
            else
                outlolmes();
        }
        return;
    }
    static int command;

private:
    list<int> mesque;
    mutex mu1;
    mutex mu2;
    condition_variable my_cond;
};
int A::command = 0; /* 要这样给类的静态成员变量赋值 */

int main()
{
    A a;
    thread th2(&A::outmes, &a);
    thread th1(&A::inmes, &a);
    th2.join();
    th1.join();
    cout << "hello mutex" << endl;
    return 0;
}