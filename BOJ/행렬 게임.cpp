#include <iostream>
#include <cmath>
#include <algorithm>

// 32822번 행렬 게임 

using namespace std;

int n, m, A[1005][1005], B[1005][1005], diff[1005], ans, b;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      cin >> B[i][j];
    }
  }
  for(int c = 0; c < n; c++) {
    for(int r = 0; r < n; r++) {
      diff[c] = max(diff[c], abs(A[r][c] - B[r][c]));
    }
//		cout << '#' << c << " " << diff[c] << endl;
  }
  while(m--) {
    cin >> b;
    ans += diff[--b];
  }
  cout << ans;
  cin >> n;

  return 0;
}