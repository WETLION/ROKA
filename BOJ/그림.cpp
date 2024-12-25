#include <iostream>
#include <queue>
#include <algorithm>

// 1926번 그림 

using namespace std;

struct node {
  int x, y;
};

int n, m, map[500][500], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, ans_cnt, ans;

void bfs(int y, int x) {
  int cnt = 1; // 한 칸인 경우 문제가 됨 
  ans_cnt++;
  queue<node> q;
  q.push({x, y});
  map[y][x] = 0; // 시작점 초기화 
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int xx = now.x + dx[i], yy = now.y + dy[i];
      if(0 <= xx && xx < m && 0 <= yy && yy < n && map[yy][xx]) {
        map[yy][xx] = 0;
        q.push({xx, yy});
        cnt++;
      }
    }
  }
  ans = max(ans, cnt);
} 

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(map[i][j]) bfs(i, j);
    }
  }
  cout << ans_cnt << endl << ans;

  return 0;
}