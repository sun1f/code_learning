#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using namespace std;

class A
{
public:
    void inmes()
    {
        for (int i = 0; i < 100000; ++i)
        {
            cout << "A:inmes() begins to work" << endl;
            unique_lock<mutex> sbguard(mu1);

            /* chrono::milliseconds dura(20);
            this_thread::sleep_for(dura); */

            mesque.push_back(i);
            cout << "i= " << i << endl;
        }
        return;
    }
    bool outlolmes()
    {
        unique_lock<mutex> sbguard(mu1, try_to_lock);
        if (sbguard.owns_lock())
        {
            if (!mesque.empty())
            {
                int command = mesque.front();
                cout << "A::outmes() is working, and conmmand = " << command << endl;
                mesque.pop_front();
                return true;
            }
            return false;
        }
        else
        {
            cout << "do something else instaed" << endl;
        }
        return false;
    }
    void outmes()
    {
        for (int i = 0; i < 100000; ++i)
        {
            if (!outlolmes())
                cout << "mesqueue is empty" << endl;
        }
    }

private:
    list<int> mesque;
    mutex mu1;
    mutex mu2;
};

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