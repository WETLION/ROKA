#include <iostream>
#include <algorithm>
#include <cmath>

// 2548번 대표 자연수

using namespace std;

int n, arr[20001], chk[10001], m = 1000000000, ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  for(int i = 0; i < n; i++) {
    if(chk[arr[i]]) continue;
    chk[arr[i]] = 1;
    int sum = 0;
    for(int j = 0; j < n; j++) {
      sum += abs(arr[i] - arr[j]);
    }
    if(m > sum) {
      m = sum;
      ans = arr[i];
    }
  }
  cout << ans;

  return 0;
} 