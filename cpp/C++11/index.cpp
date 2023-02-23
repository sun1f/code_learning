#include <vector> 
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> v1(v.begin(), v.begin() + 2);
    vector<int> v2(v.begin() + 3, v.end());

    for(int x : v1) 
        cout << x;

    cout << endl << "-----------" << endl;

    for(int x : v2) 
        cout << x;

    return 0;
}