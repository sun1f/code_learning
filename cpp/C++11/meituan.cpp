#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void fun(int n, int m)
{
    double res = n * 1.0;
    while (--m)
    {
        res += (double)sqrt(n);
        n = (double)sqrt(n);
    }
    /* cout << setprecision(2) << res << endl; */
    printf("%.2f\n", res);
}

int main(int argc, char **argv)
{
    fun(81, 4);
    return 0;
}