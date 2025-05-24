#include <iostream>

// 1736번 쓰레기 치우기

using namespace std;

int n, m, map[100][100], chk[100][100], ans;

struct node {
	int chk, location;
};

node find_y(int x, int y) {
	node ret = {0, -1};
	for(int i = y; i >= 0; i--) {
		if(chk[i][x]) break;
		if(map[i][x]) {
			ret.chk = 1;
			ret.location = i;
		}
		chk[i][x] = 1;
//		cout << x << " " << i << endl;
	}
	return ret;
}

int find_map(int x) {
	int ret = 0, trash = n - 1;
	for(int i = x; i >= 0; i--) {
		node temp = find_y(i, trash);
//		cout << temp << endl;
		if(temp.chk) { // 기존 코드에서는 temp == trash인 경우 로봇이 필요없다고 판단했으나, node 구조체를 이용하여 무조건 경로에 있는지 없는지 검사 
			ret = 1;
			trash = temp.location;
		}
	}
//	cout << endl;
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> map[i][j];
	for(int i = m - 1; i >= 0; i--) {
		if(chk[n - 1][i]) continue;
		ans += find_map(i);
	}	
	cout << ans;
	cin >> n;

	return 0;
} 