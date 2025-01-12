#include <iostream>
#include <queue>

// 15671번 오델로 

using namespace std;

struct node {
  int r, c;
};

int n, r, c, map[10][10] = {{0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 1, -1, 0, 0}, {0, 0, -1, 1, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}}, b, w; // 1이 백색, -1이 흑색 

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> r >> c;
    r--;
    c--;
    map[r][c] = i % 2 ? 1 : -1; // 나누어 떨어지면 흑색인데 반대로 줌 
    // not(!) 붙이는 실수
    queue<node> q;
    for(int j = r - 1; j >= 0; j--) {
      if(map[j][c] && map[j][c] != map[r][c]) q.push({j, c});
      else if(map[j][c] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][c]) break;
    }
    q = queue<node>(); // 만약 큐가 찬 상태로 나오면 에러가 됨 
    for(int j = r + 1; j < 6; j++) {
      if(map[j][c] && map[j][c] != map[r][c]) q.push({j, c});
      else if(map[j][c] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][c]) break;
    }
    q = queue<node>(); // 만약 큐가 찬 상태로 나오면 에러가 됨 
    for(int j = c - 1; j >= 0; j--) {
      if(map[r][j] && map[r][j] != map[r][c]) q.push({r, j}); // map[r][c]랑 비교해야하는데 map[r][j]랑 비교함
      else if(map[r][j] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[r][j]) break;
    }
    q = queue<node>(); // 만약 큐가 찬 상태로 나오면 에러가 됨 
    for(int j = c + 1; j < 6; j++) {
      if(map[r][j] && map[r][j] != map[r][c]) q.push({r, j}); // map[r][c]랑 비교해야하는데 map[r][j]랑 비교함
      else if(map[r][j] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[r][j]) break;
    }
    q = queue<node>();
    for(int j = r - 1, k = c - 1; j >= 0 && k >= 0; j--, k--) { // 만약 r이나 c가 0인 경우 음수로 떨어짐 
      if(map[j][k] && map[j][k] != map[r][c]) q.push({j, k});
      else if(map[j][k] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][k]) break;
    }
    q = queue<node>();
    for(int j = r + 1, k = c - 1; j < 6 && k >= 0; j++, k--) { // 만약 r이나 c가 0인 경우 음수로 떨어짐 
      if(map[j][k] && map[j][k] != map[r][c]) q.push({j, k});
      else if(map[j][k] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][k]) break;
    }
    q = queue<node>();
    for(int j = r - 1, k = c + 1; j >= 0 && k < 6; j--, k++) { // 만약 r이나 c가 0인 경우 음수로 떨어짐 
      if(map[j][k] && map[j][k] != map[r][c]) q.push({j, k});
      else if(map[j][k] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][k]) break;
    }
    q = queue<node>();
    for(int j = r + 1, k = c + 1; j < 6 && k < 6; j++, k++) {
      if(map[j][k] && map[j][k] != map[r][c]) q.push({j, k});
      else if(map[j][k] == map[r][c]) {
        while(!q.empty()) {
          node now = q.front();
          q.pop();
          map[now.r][now.c] = map[r][c];
        }
        break;
      }
      else if(!map[j][k]) break;
    }
//		for(int i = 0; i < 6; i++) {
//			for(int j = 0; j < 6; j++) {
//				if(!map[i][j]) cout << '.';
//				else if(map[i][j] > 0) {
//					cout << 'W';
//				}
//				else {
//					cout << 'B';
//				}
//			}
//			cout << endl;
//		}
  }
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 6; j++) {
      if(!map[i][j]) cout << '.';
      else if(map[i][j] > 0) {
        w++;
        cout << 'W';
      }
      else {
        b++;
        cout << 'B';
      }
    }
    cout << endl;
  }
  cout << (b > w ? "Black" : "White");
  cin >> n;

  return 0;
}