#include <iostream>
#include <algorithm>
#include <cmath>

// 2758번 로또 

using namespace std;

long long t, n, m, ans, arr[2001][2001]; // 숫자의 위치에 따라 가능한 경우의 수가 바뀌므로 두 가지를 모두 저장해야함. 

long long make_arr(int num, int cnt) {
	if(cnt < 0) return 1;
	if(arr[cnt][num]) return arr[cnt][num];
	long long limit = m / pow(2, cnt);
	for(int i = num * 2; i <= limit; i++) {
//		cout << i << " " << limit << endl;
		arr[cnt][num] += make_arr(i, cnt - 1);
	}
//	cout << "##" << cnt << " " << num << " " << arr[cnt][num] << endl;
	return arr[cnt][num];
}

int main() {
	cin >> t;
	while(t--) {
		cin >> n >> m;
		ans = 0;
		for(int i = 0; i <= n; i++) { // 초기화 범위 오류 
			for(int j = 1; j <= m; j++) {
				arr[i][j] = 0;
			}
		}
		for(long long i = m; i > m / 2; i--) arr[0][i] = 1;
		int limit = m / pow(2, --n);
		for(int i = 1; i <= limit; i++) ans += make_arr(i, n - 1);
		cout << ans << endl;
	}
	cin >> t;

	return 0;
}