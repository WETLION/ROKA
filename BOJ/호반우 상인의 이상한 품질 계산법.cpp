#include <iostream>
#include <algorithm>

// 20117번 호반우 상인의 이상한 품질 계산법 

using namespace std;

int n, arr[100001], ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if(n % 2) {
    ans += arr[n / 2];
  }
  for(int i = 0; i < n / 2; i++) {
    ans += arr[n / 2 + i + n % 2] * 2;
  }
  cout << ans;
//	cin >> n;

  return 0;
}