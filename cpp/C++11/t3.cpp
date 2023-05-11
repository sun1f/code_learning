#include <iostream>

using namespace std;

void Sort(int n, float *w, float *v)
{
    int i = 0, j = 0;
    float temp1 = 0, temp2 = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n - i; ++j)
        {
            temp1 = v[j] / w[j];
            temp2 = v[j + 1] / w[j + 1];
            if (temp1 < temp2)
            {
                swap(w[j], w[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    float w[100000];
    float a[100000];
    float b[100000];
    float v[100000];
    float count = 0.0;
    int n;
    float M;
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = 1; i <= n; ++i)
        v[i] = b[i] - a[i];

    Sort(n, w, v);
    int i;
    float c = M;
    for(int i = 1; i <= n; ++i) {
        if(c < w[i])
            break;
        count += v[i];
        c -= w[i];
    }
    cout << count << endl;
    return 0;
}