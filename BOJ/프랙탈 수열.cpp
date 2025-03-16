#include <iostream>

// 31499번 프랙탈 수열 

using namespace std;

int n, m;
long long ans = 1;

int main() {
	cin >> n >> m;
	for(int i = 2; i <= n; i++) {
		ans = ((ans % m) * (i % m)) % m;
	}
	cout << ans % m; // n == 1, m == 1인 경우 0을 출력해야함.
	cin >> n;

	return 0;
}