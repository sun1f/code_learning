#include <iostream>
#include <string>

using namespace std;

void printcolor(string color, string str)
{
    int clr;
    string head;
    string tail;
    string display;
    if (color == "red")
        clr = 1;
    if (color == "green")
        clr = 2;
    switch (clr)
    {
    case 1:
    {
        head = "\033[31m";
        tail = "\033[0m";
        display = head + str + tail;
        break;
    }
    case 2:
    {
        head = "\033[32m";
        tail = "\033[0m";
        display = head + str + tail;
        break;
    }
    default:
    {
        display = str;
        break;
    }
    }
    cout << display << endl;
}

int main()
{
    printcolor("red", "helloworld!");
    printcolor("green", "helloworld!");
    return 0;
}