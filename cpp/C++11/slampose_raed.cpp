/**
 * @file io3.cpp
 * @author elliot (versonpill120@gmail.com)
 * @brief A function that can read a specific range of columns from a specified file,
 * pose data analysis that can be used for SLAM.
 * @version 0.1
 * @date 2023-01-22
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string filename;
    cin >> filename;
    ifstream myfile(filename);
    while (!myfile)
    {
        cout << "Error opening " << filename << " for input" << endl;
        cout << "input again" << endl;
        cin >> filename;
        myfile.open(filename);
        // exit(-1);
    }

    vector<string> vec;
    string temp;

    while (getline(myfile, temp)) // 利用getline（）读取每一行，并按照行为单位放入到vector
    {
        vec.push_back(temp);
    }

    vector<string> radius;

    cout << "读入的数据为 " << endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        cout << *it << endl;
        istringstream is(*it); // 用每一行的数据初始化一个字符串输入流
        string s;
        int pam = 0;

        while (is >> s) // 以空格为界，把istringstream中数据取出依次放入到s中
        {
            if (pam < 4) // 获取前4列的数据
            {
                radius.push_back(s);
            }
            pam++;
        }
    }

    ofstream out("out.txt");
    out << "io.txt中前四列数据为" << endl;
    int count = 1;
    for (auto it = radius.begin(); it != radius.end(); it++)
    {
        out << *it << " ";
        if (count == 4)
        {
            out << endl;
            count = 0;
        }
        count++;
    }
    myfile.close();
    cout << "working... new file will named as out.txt" << endl;
    system("pause");
    return 0;
}