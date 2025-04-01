#include <iostream>

// 2688번 줄어들지 않아

using namespace std;

int t, n;
long long arr[65][10] = {{}, {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, ans[65] = {0, 10}; // 1의 경우 전처리에서 계산하지 않으므로 미리 초기화해야함.

int main() {
	for(int i = 2; i <= 64; i++) {
		for(int j = 0; j < 10; j++) {
			for(int k = j; k < 10; k++) {
				arr[i][j] += arr[i - 1][k];
			}
			ans[i] += arr[i][j];
		}
	}
	cin >> t;
	while(t--) {
		cin >> n;
		cout << ans[n] << endl;
	}
	cin >> t;

	return 0;
} 