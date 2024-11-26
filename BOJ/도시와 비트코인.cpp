#include <iostream>
#include <queue>

// 31575번 도시와 비트코인

using namespace std;

struct node {
  int x, y;
};

int n, m, arr[500][500], chk[500][500], dx[4] = {1, 0}, dy[4] = {0, 1};
queue<node> q;

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }
  q.push({0, 0});
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.x == n - 1 && now.y == m - 1) {
      cout << "Yes";
      return 0;
    }
    for(int i = 0; i < 2; i++) {
      int xx = now.x + dx[i], yy = now.y + dy[i];
      if(xx < n && yy < m && xx >= 0 && yy >= 0 && arr[yy][xx] && !chk[yy][xx]) {
        chk[yy][xx] = 1;
        q.push({xx, yy});
      }
    }
  }
  cout << "No";

  return 0;
} 