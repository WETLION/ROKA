#include <iostream>

// 31821번 학식 사주기

using namespace std;

int n, m, arr[10], ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  cin >> m;
  for(int i = 0; i < m; i++) {
    cin >> n;
    ans += arr[n - 1];
  }
  cout << ans;

  return 0;
}