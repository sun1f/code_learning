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
    // ��ֵ����
    cout << "const Buffer &buf\n";
}

void SetBuffer(Buffer &&buf)
{
    // ��ֵ����
    cout << "Buffer &&buf\n";
}

int main()
{
    cout << "Hello World" << endl;

    /* Buffer buf = getBuffer();
    SetBuffer(buf); */
    const Buffer &buf = getBuffer(); // ��һ��������ָ��һ������ֵ����ô�������ֵ���������ھͻᱻ�ӳ����������������ͬ�ĳ���
    SetBuffer(buf);

    SetBuffer(getBuffer()); // ����ֵ���������ӳ���������û����
    return 0;
}
