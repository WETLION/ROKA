#include <iostream>
#include <queue>

// 17129번 윌리암슨수액빨이딱따구리가 정보섬에 올라온 이유

using namespace std;

struct node {
  int x, y, cnt;
};

int n, m, map[3000][3000], visit[3000][3000], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
string str;
queue<node> q;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> str;
    for(int j = 0; j < m; j++) {
      map[i][j] = str[j] - '0';
      if(map[i][j] == 2) {
        q.push({j, i, 1});
        visit[i][j] = 1;
      }
    }
  }
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    for(int i = 0; i < 4; i++) {
      int xx = now.x + dx[i], yy = now.y + dy[i];
      if(0 <= xx && xx < m && 0 <= yy && yy < n && map[yy][xx] != 1 && !visit[yy][xx]) {
        if(!map[yy][xx]) {
          q.push({xx, yy, now.cnt + 1});
          visit[yy][xx] = 1; // 방문 체크 안해서 메모리 초과 
        }
        else {
          cout << "TAK" << endl << now.cnt;
//					cin >> n;
          return 0;
        }
      }
    }
  }
  cout << "NIE";
//	cin >> n;

  return 0;
} 