#include <iostream>
#include <algorithm>

// 2805번 나무 자르기 

using namespace std;

long long n, m, arr[1000000], l, mid, r, ans, sum;

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		r = max(r, arr[i]);
	}
	while(l <= r) {
		mid = (l + r) / 2;
		sum = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i] - mid > 0) sum += arr[i] - mid;
		}
		if(sum >= m) {
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans;
	cin >> n;

	return 0;
}