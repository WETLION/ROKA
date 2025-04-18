#include <iostream>

// 1437번 수 분해 

using namespace std;

long long n, arr[1000001], ans = 1;

int main() {
	cin >> n;
	if(n < 2) {
		cout << n;
		return 0;
	}
	while(n % 3) {
		ans *= 2;
		if(ans >= 10007) ans %= 10007;
		n -= 2;
	}
	while(n) {
		ans *= 3;
		if(ans >= 10007) ans %= 10007;
		n -= 3;
	}
	cout << ans;
	cin >> n;

	return 0;
}