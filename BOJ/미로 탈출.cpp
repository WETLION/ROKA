#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 14923번 미로 탈출

using namespace std;

struct node {
  int x, y, cnt;
};

int n, m, ans = -1, map[1001][1001], dest[1001][1001], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<node> v;
node h, e;
queue<node> q;

int main() {
  cin >> n >> m >> h.y >> h.x >> e.y >> e.x;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
      if(map[i][j]) {
        v.push_back({j, i, -1});
        dest[i][j] = map[i][j] = -1;
      }
    }
  }
  h.x--;
  h.y--;
  e.x--;
  e.y--;

  q.push(h); // 출발지부터 모든 칸들의 거리 
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.x == e.x && now.y == e.y) {
      ans = now.cnt;
      continue;
    }
    for(int i = 0; i < 4; i++) {
      int xx = now.x + dx[i], yy = now.y + dy[i];
      if(0 <= xx && xx < m && 0 <= yy && yy < n && !map[yy][xx]) { // n 범위 지정 오류 
        q.push({xx, yy, now.cnt + 1});
        map[yy][xx] = now.cnt + 1;
      }
    }
  }
  map[h.y][h.x] = 0;

  q.push(e); // 목적지부터 모든 칸들의 거리 
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int xx = now.x + dx[i], yy = now.y + dy[i];
      if(0 <= xx && xx < m && 0 <= yy && yy < n && !dest[yy][xx]) { // n 범위 지정 오류 
        q.push({xx, yy, now.cnt + 1});
        dest[yy][xx] = now.cnt + 1;
      }
    }
  }
  dest[e.y][e.x] = 0;

//	cout << endl;
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m; j++) {
//			cout.width(2);
//			cout.fill(' ');
//			cout << map[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m; j++) {
//			cout.width(2);
//			cout.fill(' ');
//			cout << dest[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;

  for(node k: v) {
    int map_min = 123456789, dest_min = 123456789;
    for(int i = 0; i < 4; i++) {
      int xx = k.x + dx[i], yy = k.y + dy[i];
      if(0 <= xx && xx < m && 0 <= yy && yy < n && map[yy][xx] > 0) {
//				cout << k.x << " " << k.y << " " << xx << " " << yy << " " << map[yy][xx] << " " << dest[yy][xx] << endl;
        map_min = min(map_min, map[yy][xx]);
        dest_min = min(dest_min, dest[yy][xx]);
      }
    }
    if(map_min != 123456789) {
      ans = min(ans, map_min + dest_min + 2); // dest와 map 모두 0에서 시작하므로 벽 1칸 + 1칸 해줘야힘. 
    }
  }
  cout << ans;
//	cin >> n;

  return 0;
}