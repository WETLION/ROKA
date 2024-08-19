#include <iostream>

// 13900번 순서쌍의 곱의 합

using namespace std;

long long sum, n, arr[100001], ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  for(int i = 0; i < n; i++) {
    sum -= arr[i];
    ans += sum * arr[i];
  }
  cout << ans;

  return 0;
}