#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for(int i = 0; i < N - 1; ++i) {
        int sum = 0, num = 0;
        while(cin >> num) {
            sum += num;
            if(cin.get() == '\n')
                break;
        }
        cout << sum << endl;
    }
    int a, b;
    cin >> a >> b;
    cout << a + b;
    system("pause");
    return 0;
}