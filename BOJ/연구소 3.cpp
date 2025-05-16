#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

// 17142번 연구소 3

using namespace std;

struct node {
	int x, y, cnt;
};

int n, m, map[50][50], arr[10][50][50], chk[10][50][50], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
queue<node> q;
vector<node> virus;

bool isit_now(int i, int j, vector<int> v) {
	for(int k: v) {
		if(virus[k].x == j && virus[k].y == i) return true;
	}
	return false;
}

int find_ans(int start, int cnt, vector<int> v) {
	int ret = -1;
	if(!cnt) {
//		for(int i: v) cout << i << " ";
//		cout << endl << endl;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(map[i][j] == 1 || map[i][j] == 2 && !isit_now(i, j, v)) {
//					cout << "  ";
					continue;
				}
				int cmp = -1;
				for(int k: v) {
					if(!arr[k][i][j] && !chk[k][i][j]) continue;
					else if(cmp < 0) cmp = arr[k][i][j];
					else cmp = min(cmp, arr[k][i][j]);
				}
//				cout << cmp << " ";
				if(cmp < 0) return -1;
				ret = max(cmp, ret);
			}
//			cout << endl;
		}
//		cout << endl;
		return ret;
	}
	for(int i = start; i <= virus.size() - cnt; i++) { // 숫자 범위 지정 오류
		v.push_back(i);
		int cmp = find_ans(i + 1, cnt - 1, v);
		if(cmp >= 0) {
			if(ret < 0) ret = cmp;
			else ret = min(ret, cmp);
		}
		v.pop_back();
	}
	return ret;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 2) {
				chk[virus.size()][i][j] = 1;
				virus.push_back({j, i, 1});
			}
		}
	}
	for(int k = 0; k < virus.size(); k++) {
		q.push(virus[k]);
		while(!q.empty()) {
			node now = q.front();
			q.pop();
			for(int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i];
				if(xx >= 0 && yy >= 0 && xx < n && yy < n && !chk[k][yy][xx] && map[yy][xx] != 1) {
					arr[k][yy][xx] = now.cnt;
					chk[k][yy][xx] = 1;
					q.push({xx, yy, now.cnt + 1});
				}
			}
		}
	}
	cout << find_ans(0, m, vector<int>());
	cin >> n;

	return 0;
}