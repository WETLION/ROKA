#include <iostream>
#include <cmath>
#include <algorithm> 

// 10653번 마라톤 2 

using namespace std;

int n, k, a[1000], b[1000], arr[1000][1000], dist[1000][1000], ans;

int main() {
	cin >> n >> k;
	if(k == n - 1) k--;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			dist[i][j] = abs(a[j] - a[i]) + abs(b[j] - b[i]);
		}
	}
	for(int i = 1; i < n; i++) {
		arr[i][0] = arr[i - 1][0] + dist[i - 1][i];
//		cout << i << " " << 0 << " " << arr[i][0] << endl;
		for(int j = 1; j <= min(k, i - 1); j++) {
			arr[i][j] = arr[i - j - 1][0] + dist[i - j - 1][i];
			for(int l = 1; l <= j; l++) {
				if(i - j - 1 == 0) continue; // 점의 위치와 같은 숫자로 점을 뛰어넘을수 없음. 
				arr[i][j] = min(arr[i][j], arr[i - j - 1 + l][l] + dist[i - j - 1 + l][i]); // 이 방식으로 바꾸고 성공인데 정확한 사유는 모르겠음. 함수쪽에 문제가 있었던듯? 
			}
//			cout << endl << i << " " << j << " " << arr[i][j] << endl;
		}
	}
//	ans = arr[n - 1][0];
//	for(int i = 1; i <= k; i++) ans = min(ans, arr[n - 1][i]);
	cout << arr[n - 1][k];
	cin >> n;

	return 0;
}