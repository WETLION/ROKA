#include <iostream>

// 33612번 피갤컵

using namespace std;

int n, y = 2024, m = 8;

int main() {
	cin >> n;
	m += (n - 1) * 7;
	while(m > 12) {
		y++;
		m -= 12;
	}
	cout << y << ' ' << m;

	return 0;
}