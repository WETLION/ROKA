#include <iostream>

// 16507번 어두운 건 무서워

using namespace std;

int r, c, q, map[1001][1001], arr[1001][1001], r1, r2, c1, c2;

int main() {
	cin >> r >> c >> q;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
		arr[i][1] = map[i][0]; // 만약 c가 0이면 빛이 없으므로 0
	}
	for(int i = 0; i < r; i++) {
		for(int j = 1; j < c; j++) {
			arr[i][j + 1] = map[i][j] + arr[i][j];
		}
	}
	while(q--) {
		int ans = 0;
		cin >> r1 >> c1 >> r2 >> c2;
		c1--;
		for(int i = --r1; i < r2; i++) {
			ans += arr[i][c2] - arr[i][c1]; // arr[r][0]가 전부 0으로 지정되었으므로, 한 칸씩 옆으로 밀리며 뺄셈을 안해도 됨
			// cout << "#" << ans << endl;
		}
		cout << ans / ((r2 - r1) * (c2 - c1)) << endl;
	}

	return 0;
}