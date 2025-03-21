#include <iostream>
#include <algorithm>

// 28217번 두 정삼각형 

int n, arr[3][10][10], temp[2][10][10], ans = 1000;

int cmp(int b[10][10]) {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			cnt += arr[2][i][j] != b[i][j];
		}
	}
	return cnt;
}

using namespace std;

int main() {
	cin >> n;
	for(int k = 0; k < 3; k = k + 2) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j <= i; j++) {
				cin >> arr[k][i][j];
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			arr[1][i][j] = arr[0][i][i - j];
//			cout << arr[1][i][j] << " ";
		}
//		cout << endl;
	}
	ans = min(ans, min(cmp(arr[1]), cmp(arr[0])));
	for(int j = 0; j < 2; j++) {
		for(int t = 0; t < 2; t++) {
			for(int k = 0; k <= n / 3 - !(n % 3); k++) {
				for(int i = k * 2; i < n - k; i++) {
					temp[t][i][i - k] = arr[t][n - i - 1 + k][k];
					temp[t][n - 1 - k][n - i - 1] = arr[t][i][i - k];
					temp[t][n - i - 1 + k][k] = arr[t][n - 1 - k][n - i - 1];
	//				cout << i << " " << n - i - 1 << " " << arr[0][n - i - 1][0] << endl;
				}
			}

			for(int i = 0; i < n; i++) {
				for(int j = 0; j <= i; j++) {
//					cout << temp[t][i][j] << " ";
					arr[t][i][j] = temp[t][i][j];
				}
//				cout << endl;
			}
		}
		ans = min(ans, min(cmp(arr[1]), cmp(arr[0])));
	}
	cout << ans;
	cin >> n;

	return 0;
}