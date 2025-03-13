#include <iostream>

// 30007번 라면 공식 

using namespace std;

int n, a, b, x; 

int main() {
	cin >> n;
	while(n--) {
		cin >> a >> b >> x;
		cout << a * (x - 1) + b << endl;
	}

	return 0;
}