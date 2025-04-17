#include <iostream>

// 17300번 패턴

using namespace std;

int l, before, now, chk[10] = {1}, arr[10][3][2] = {{}, {{3, 2}, {7, 4}, {9, 5}}, {{8, 5}}, {{1, 2}, {7, 5}, {9, 6}}, {{6, 5}}, {}, {{4, 5}}, {{1, 4}, {3, 5}, {9, 8}}, {{2, 5}}, {{1, 5}, {3, 6}, {7, 8}}};
bool chk_used(int before, int now) {
	for(int i = 0; i < 3; i++) {
		if(arr[before][i][0] == now && !chk[arr[before][i][1]]) return true;
	}
	return false;
}

int main() {
	cin >> l >> before;
	chk[before] = 1;
	while(--l) {
		cin >> now;
		if(chk[now] || chk_used(before, now)) {
			cout << "NO";
			return 0;
		}
		chk[before = now] = 1; // 현재 점을 방문 체크해야하는데 과거 점을 방문 체크 해버림;; 
	}
	cout << "YES";
	cin >> l;

	return 0;
} 