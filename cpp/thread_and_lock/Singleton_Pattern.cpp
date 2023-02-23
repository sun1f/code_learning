#include <iostream>
#include <thread>
#include <list>
#include <mutex>

using namespace std;
mutex resource_mutex;
class sp
{
private:
    sp(){};
    static sp *my_instance;

public:
    static sp *getinstance()
    {
        if (my_instance == NULL) /* double check, 提高效率 */
        {
            unique_lock<mutex> my_mutex(resource_mutex);
            if (my_instance == NULL)
            {
                my_instance = new sp();
                static sp_recycle re;
            }
        }
        return my_instance;
    }
    void func()
    {
        cout << "tseting ... " << endl;
    }
    class sp_recycle
    {
    public:
        ~sp_recycle()
        {
            if (sp::my_instance)
            {
                delete sp::my_instance;  /* delete释放的是my_instance指针所指向的内存，但不会删除指针my_instance本身 */
                sp::my_instance == NULL; /* 所以需要这一行 */
                cout << "~sp_recycle()被执行" << endl;
            }
        }
    };
};
sp *sp::my_instance = NULL; /* 为什么能对私有成员赋值 */

void my_thread()
{
    cout << "my_thread开始执行" << endl;
    sp *sp1 = sp::getinstance();
    sp1->func();
    cout << "my_thread执行完毕" << endl;
    return;
}
int main()
{
    // sp *s1 = sp::getinstance();
    /* thread th1(sp::getinstance()->func());
    thread th2(sp::getinstance()->func()); */
    // s1->func();
    thread th1(my_thread);
    thread th2(my_thread);
    th1.join();
    th2.join();
    return 0;
}