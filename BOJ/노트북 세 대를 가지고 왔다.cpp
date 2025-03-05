#include <iostream>

// 33315번 노트북 세 대를 가지고 왔다 

using namespace std;

int a, b;

int main() {
	cin >> a >> b;
	cout << (a > b ? b : a);

	return 0;
}