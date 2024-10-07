#include <iostream>

// 16956번 늑대와 양

using namespace std;

int r, c;
char arr[1000][1000];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cin >> arr[i][j];
      if(arr[i][j] == '.') arr[i][j] = 'D';
    }
  }
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      for(int k = 0; k < 4; k++) {
        int xx = j + dx[k], yy = i + dy[k];
        if(xx >= 0 && yy >= 0 && xx < c && yy < r && arr[i][j] != 'D' && arr[yy][xx] != 'D' && arr[i][j] != arr[yy][xx]) {
          cout << 0;
          return 0;
          // 조건문 이슈 : xx < r, yy < c, arr[xx][yy] => bfs를 너무 오랜만에 한듯
        }
      }
    }
  }
  cout << 1 << endl; // 1 출력 까먹음
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }

  return 0;
}