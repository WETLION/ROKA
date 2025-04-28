#include <iostream>
#include <algorithm>
#include <cmath>

// 27295번 선형 회귀는 너무 쉬워 1

using namespace std;

long long n, b, x, y, x_i, y_i;

long long __gcd__(long long a, long long b) {
	return a % b ? __gcd__(b, a % b) : b;
}

int main() {
	cin >> n >> b;
	b *= n;
	while(n--) {
		cin >> x_i >> y_i;
		x += x_i;
		y += y_i;
	}
	y -= b;
	if(!x) cout << "EZPZ";
	else if(y == 0) cout << 0;
	else {
		long long gcd = __gcd__(abs(max(x, y)), abs(min(x, y)));
		if(x < 0) {
			x *= -1;
			y *= -1;
		}
		cout << y / gcd;
		if(x / gcd != 1) cout << '/' << x / gcd;
	}
	cin >> n;

	return 0;
} 