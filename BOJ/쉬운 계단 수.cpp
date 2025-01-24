#include <iostream>

// 10844번 쉬운 계단 수

using namespace std;

long long n, arr[100][10] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}}, ans;

int main() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    arr[i][0] = arr[i - 1][1];
    for(int j = 1; j < 9; j++) {
      arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j + 1]) % 1000000000;
    }
    arr[i][9] =  arr[i - 1][8];
  }
  for(int i = 1; i < 10; i++) {
    ans += arr[n - 1][i];
  }
  cout << ans % 1000000000;
  cin >> n;

  return 0;
} 