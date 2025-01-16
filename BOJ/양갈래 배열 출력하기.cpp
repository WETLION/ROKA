#include <iostream>
#include <queue>
#include <cstdio>

// 31475번 양갈래 배열 출력하기 

using namespace std;

struct node {
  int num, way, x, y, turn; // 0 == Up, 1 == Right, 2 == Down, 3 == Left to way
};

int n, m, arr[2001][2001], dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0}, chk;
string str;
queue<node> q;

int main() {
  cin >> n >> m >> str;
  switch(str.front()) {
    case 'U':
      q.push({1, 2, m / 2, 0, 0});
      break;
    case 'D':
      q.push({1, 0, m / 2, n - 1, 0});
      break;
    case 'L':
      q.push({1, 1, 0, n / 2, 0});
      break;
    case 'R':
      q.push({1, 3, m - 1, n / 2, 0});
      break;
  }
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    arr[now.y][now.x] = now.num;
    int xx = now.x + dx[now.way], yy = now.y + dy[now.way];
//		cout << now.num << " " << now.y << " " << now.x << " " << now.way << " " << now.turn << endl;
    if(0 <= xx && xx < m && 0 <= yy && yy < n && !arr[yy][xx]) {
      q.push({now.num + 1, now.way, xx, yy, now.turn});
    }
    else if(!chk) {
      int right = (now.way + 1) % 4, left = now.way - 1 < 0 ? now.way + 3 : now.way - 1;
      q.push({now.num + 1, right, now.x + dx[right], now.y + dy[right], now.turn});
      q.push({now.num + 1, left, now.x + dx[left], now.y + dy[left], 1});
      chk = 1;
    }
    else {
      now.way = now.turn ? now.way - 1 < 0 ? now.way + 3 : now.way - 1 : (now.way + 1) % 4;
      xx = now.x + dx[now.way];
      yy = now.y + dy[now.way];
      if(!arr[yy][xx]) q.push({now.num + 1, now.way, now.x + dx[now.way], now.y + dy[now.way], now.turn});
    }
  }
//	cout << endl;
  for(int i = 0; i < n; i++) {
    // 의외로 cout과 printf의 차이가 미미하다. 
    for(int j = 0; j < m; j++) {
//			cout << arr[i][j] << " ";
      printf("%d ", arr[i][j]);
    }
//		cout << endl;
    printf("\n");
  }
//	cin >> n;

  return 0;
}