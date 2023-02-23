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
            mu1.lock();
            mu2.lock();
            mesque.push_back(i);
            cout << "A::inmes() is working, and i = " << i << endl;
            mu2.unlock();
            mu1.unlock();
        }
        return;
    }
    bool outlolmes()
    {
        mu1.lock();
        mu2.lock();
        if (!mesque.empty())
        {
            int command = mesque.front();
            cout << "A::outmes() is working, and conmmand = " << command << endl;
            mesque.pop_front();
            mu1.unlock();
            mu2.unlock();
            return true;
        }
        mu1.unlock();
        mu2.unlock();
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