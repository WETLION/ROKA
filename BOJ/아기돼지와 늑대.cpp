#include <iostream>
#include <queue>
#include <vector>

// 16441번 아기돼지와 늑대 

using namespace std;

struct node {
	int x, y, way, slide;
};

int n, m, map[100][100], chk[100][100][4]/*방향별로 방문한 상태를 지정해주어야만 미끄러진 방향을 토대로 갈지 말지 결정이 가능함*/, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string str[100];
queue<node> q;
vector<node> v;

bool chk_empty(int y, int x) {
	for(int i = 0; i < 4; i++) if(chk[y][x][i]) return 0;
	return 1;
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> str[i];
		for(int j = 0; j < m; j++) {
			if(str[i][j] == 'W') {
				map[i][j] = 1;
				v.push_back({j, i, 0, 0});
			}
			else if(str[i][j] == '+') map[i][j] = -1;
			else if(str[i][j] == '#') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
	for(node k: v) { // 모든 늑대를 개별적으로 볼 필요 없음. 한 덩어리처럼 지나가기만 하면 되는것. 
		q.push(k);
		for(int i = 0; i < 4; i++) chk[k.y][k.x][i] = 1;
	}
	while(!q.empty()) {
		node now = q.front();
		q.pop();
		if(now.slide) {
			int xx = now.x + dx[now.way], yy = now.y + dy[now.way];
			if(0 <= xx && xx < m && 0 <= yy && yy < n && !chk[yy][xx][now.way]) {
				if(map[yy][xx] > 0) q.push({xx, yy, 0, 0});
				else if(!map[yy][xx]) q.push({now.x, now.y, 0, 0}); // 벽에 부딫힌 경우 제자리에 멈춰야함. 
				else q.push({xx, yy, now.way, 1});
				chk[yy][xx][now.way] = 1;
			}
		}
		else {
			for(int i = 0; i < 4; i++) {
				int xx = now.x + dx[i], yy = now.y + dy[i];
				if(0 <= xx && xx < m && 0 <= yy && yy < n && !chk[yy][xx][i] && map[yy][xx]) {
					if(map[yy][xx] > 0) q.push({xx, yy, 0, 0});
					else q.push({xx, yy, i, 1});
					chk[yy][xx][i] = 1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(map[i][j] == 1 && chk_empty(i, j)) cout << 'P';
			else cout << str[i][j];
		}
		cout << endl;
	}
	cin >> n;

	return 0;
}