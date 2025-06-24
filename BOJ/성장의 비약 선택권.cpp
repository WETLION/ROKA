#include <iostream>

// 26645번 성장의 비약 선택권 

using namespace std;

int n; 

int main() {
	cin >> n;
	cout << (n < 206 ? 1 : n < 218 ? 2 : n < 229 ? 3 : 4);

	return 0;
}
