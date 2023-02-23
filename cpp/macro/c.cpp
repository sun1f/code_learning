#include <iostream>
using namespace std;

#define Conn(x, y) x##y

int main() {
	cout << Conn(123, 456) << endl;
	//char* str = Conn("asdf", "adf"); /*结果就是 str = "asdfadf";*/
	//cout << str << endl;
	//cout << Conn("syf", "best") << endl;
	cout << int('17') << endl;
	return 0;
}
