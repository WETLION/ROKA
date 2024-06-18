#include <algorithm>
#include <iostream>

// 1292번 쉽게 푸는 문제

using namespace std;

int arr[1001], a, b, cnt = 1, ans;

int main() {
  cin >> a >> b;
  for (int i = 1; i <= 1000;) {
    for (int j = 0; j < cnt && i <= 1000; i++, j++) {
      arr[i] = cnt;
    }
    cnt++;
  }
  // for(int i = 0; i < 1000; i++) {
  //     cout << arr[i + 1] << " ";
  // }
  for (int i = a; i <= b; i++) {
    ans += arr[i];
  }
  cout << ans;

  return 0;
}