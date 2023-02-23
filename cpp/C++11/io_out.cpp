#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    int gpa[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    string name[] = {"syf", "uhus", "tom", "trump", "peter", "lucy", "leo", "kate", "Bill"};
    ofstream out;
    out.open("io.txt");
    for (int i = 0; i < 9; ++i)
    {
        out << setiosflags(ios_base::left) << setiosflags(ios_base::showpos) << setw(6) << name[i] << resetiosflags(ios_base::left) << setw(3) << gpa[i] << endl;
    }
    for (int i = 0; i < 5; ++i)
    {
        out.width(10);
        out << "syf" << endl;
    }
    out.close();
    // system("pause");
    return 0;
}
