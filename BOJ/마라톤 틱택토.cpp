#include <iostream>

// 3024번 마라톤 틱택토 

using namespace std;

int n, map[100][100], dx[4] = {1, 0, 1, -1}, dy[4] = {0, 1, 1, 1}; // 좌하로 내려가는 대각선을 고려 안함 
string str;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> str;
    for(int j = 0; j < n; j++) {
      if(str[j] == '.') map[i][j] = -1;
      map[i][j] = str[j] - 'A';
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(map[i][j] < 0) continue;
      for(int k = 0; k < 4; k++) {
        int xx = j + dx[k], yy = i + dy[k];
        if(0 <= xx && xx < n && 0 <= yy && yy <= n && map[yy][xx] == map[i][j]) {
          xx += dx[k];
          yy += dy[k];
          if(0 <= xx && xx < n && 0 <= yy && yy <= n && map[yy][xx] == map[i][j]) {
            cout << char(map[i][j] + 'A');
//						cin >> n;
            return 0;
          }
        }
      }
    }
  }
  cout << "ongoing";
//	cin >> n;

  return 0;
} 