#include <iostream>
#include <algorithm>

// 2559번 수열

using namespace std;

int n, k, sum, arr[100001], ans = -100000000; // 음수 대비 안함

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for(int i = 1; i <= n; i++) {
    sum += arr[i - 1];
    if(i >= k) {
      ans = max(ans, sum);
      sum -= arr[i - k];
    }
  }
  cout << ans;

  return 0;
}