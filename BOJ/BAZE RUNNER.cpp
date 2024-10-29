#include <iostream>
#include <algorithm>
#include <cmath>

// 16720번 BAZE RUNNER

using namespace std;

int n, arr[1001][4], ans = 100000000;
string str;

int main() {
  cin >> n;
  for(int i = 0; i < n - 2; i++) {
    cin >> str;
//		cout << "#" << str << endl;
    for(int j = 0; j < 4; j++) {
      if(str[j] == '0') {
        arr[i][j] = 1;
      }
    }
  }
  for(int k = 0; k < 4; k++) {
    int sum = 0;
    for(int i = 0; i < n - 2; i++) {
      for(int j = 0; j < 4; j++) {
        if(arr[i][j]) {
          sum += min(abs(j - k), 4 - abs(j - k)); // 왼쪽 이동 계산 실수 
          break;
        }
      }
    }
    ans = min(sum, ans);
  }

  cout << ans + 2 + n;
  cin >> n;

  return 0;
}