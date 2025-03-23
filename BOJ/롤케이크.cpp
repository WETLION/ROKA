#include <iostream>
#include <algorithm>

// 16206번 롤케이크 

using namespace std;

struct node {
	int cnt, s;
};

struct speed {
	int a, b;
};

int n, m, ans, arr[1000];

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(!(arr[i] % 10)) {
			arr[i] /= 10;
			if(m < arr[i] - 1) {
				ans += m;
				m = 0;
			}
			else {
				ans += arr[i];
				m -= arr[i] - 1;
			}
			arr[i] = 0;
		}
		else arr[i] /= 10;
	}
	sort(arr, arr + n);
	for(int i = 0; i < n; i++) {
		if(m < arr[i]) {
			ans += m;
			m = 0;
		}
		else {
			ans += arr[i];
			m -= arr[i];
		}
	}
	cout << ans;
	cin >> n;

	return 0;
} 