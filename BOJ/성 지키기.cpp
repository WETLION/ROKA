#include <iostream>

// 1236번 성 지키기

using namespace std;

bool row[101], col[101];
int n, m, cnt;
char input;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      cin >> input;
      if(input == 'X') {
        row[j] = col[i] = 1;
      }
    }
  }
  for(int i = 0; i < n; i++) {
    if(!col[i]) {
      for(int j = 0; j < m; j++) {
        if(!row[j]) {
          row[j] = 1;
          break;
        }
      }
      cnt += col[i] = 1;
    }
  }
  for(int i = 0; i < m; i++) {
    if(!row[i]) {
      for(int j = 0; j < n; j++) {
        if(!col[j]) {
          col[j] = 1;
          break;
        }
      }
      cnt += col[i] = 1;
    }
  }
  cout << cnt;

  return 0;
}