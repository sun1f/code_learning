#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void myprint(int num)
{
    cout << "子线程开始执行，线程id = " << num << endl;
    return;
}

int main()
{
    vector<thread> my_threads;
    for (int i = 0; i < 10; ++i)
    {
        my_threads.push_back(thread(myprint, i));
    }
    for (auto &it : my_threads)
    {
        it.join();
    }
    cout << "I Love Stephen Curry!" << endl;
    return 0;
}
/* int main()
{
    int i = 2;
    int &s = i;
    thread th2(myprint, s);
    th2.join();
    return 0;
} */