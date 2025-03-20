#include <iostream>

// 22113번 창영이와 버스

using namespace std;

int n, m, arr[1000][1000], bus[100], ans;

int main() {
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> bus[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i < m; i++) {
		ans += arr[bus[i - 1]][bus[i]];
	}
	cout << ans;
	cin >> n;

	return 0;
}