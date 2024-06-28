#include <iostream>

// 9626번 크로스워드 퍼즐

using namespace std;

int m, n, u, l, r, d;
string arr[30], input[10];

int main() {
  cin >> m >> n >> u >> l >> r >> d;
  for(int i = 0; i < m; i++) {
    cin >> input[i];
  }
  for(int i = 0; i < m + u + d; i++) {
    for(int j = 0; j < n + l + r; j++) {
      arr[i] += (i + j) % 2 ? '.' : '#';
    }
  }
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      arr[i + u][j + l] = input[i][j];
    }
  }

  for(int i = 0; i < m + u + d; i++) {
    for(char j: arr[i]) {
      cout << j;
    }
    cout << endl;
  }

  return 0;
}