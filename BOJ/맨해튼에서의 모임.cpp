#include <iostream>
#include <algorithm>
#include <cmath>

// 27297번 맨해튼에서의 모임

using namespace std;

int n, m;
long long arr[1001][1001], ans;

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin >> arr[j][i];
		}
	}
	for(int i = 0; i < n; i++) {
		sort(arr[i], arr[i] + m); // 정렬 까먹음;; 
		for(int j = 0; j < m; j++) {
			ans += abs(arr[i][j] - arr[i][m / 2]);
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++) cout << arr[i][m / 2] << " ";
	cin >> n;

	return 0;
} 