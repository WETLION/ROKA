#include <iostream>

// 20361번 일우는 야바위꾼

using namespace std;

int n, x, k, a, b;

int main() {
	cin >> n >> x >> k;
	while(k--) {
		cin >> a >> b;
		if(a == x) x = b;
		else if(b == x) x = a;
	}
	cout << x;

	return 0;
} 