#include <iostream>
#include <algorithm>

// 21920번 서로소 평균 

using namespace std;

int n, a[500000], x, cnt;
double ans;

int gcd(int a, int b) {
	return a % b ? gcd(b, a % b) : b;
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	cin >> x;
	for(int i = 0; i < n; i++) {
		if(gcd(max(x, a[i]), min(x, a[i])) == 1) { // 최대공약수가 1이어야 하는데 0이라고 잘못 입력함 
			cnt++;
			ans += a[i];
		}
	}
	cout << ans / cnt;

	return 0;
}
