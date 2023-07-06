#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <memory>
#include <mutex>

using namespace std;

class Buffer
{
public:
    Buffer()
    {
        buf = (char *)malloc(100);
    }
    ~Buffer()
    {
        if (buf != nullptr)
        {
            free(buf);
            buf = nullptr;
        }
    }

private:
    char *buf;
};

Buffer getBuffer()
{
    Buffer buf;
    return buf;
}

void SetBuffer(const Buffer &buf)
{
    // 左值引用
    cout << "const Buffer &buf\n";
}

void SetBuffer(Buffer &&buf)
{
    // 右值引用
    cout << "Buffer &&buf\n";
}

int main()
{
    cout << "Hello World" << endl;

    /* Buffer buf = getBuffer();
    SetBuffer(buf); */
    const Buffer &buf = getBuffer(); // 让一个常引用指向一个将亡值，那么这个将亡值的生命周期就会被延长到和这个常引用相同的长度
    SetBuffer(buf);

    SetBuffer(getBuffer()); // 将亡值生命周期延长，因此这句没报错
    return 0;
}
