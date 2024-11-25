#include <iostream>
#include <algorithm>

// 27885번 가희와 열리지 않는 건널목

using namespace std;

int time_convert(string n) {
  int h, m, s;
  h = m = s = 0;
  for(int i = 0; i < 2; i++) {
    h = h * 10 + n[i] - '0';
    m = m * 10 + n[i + 3] - '0';
    s = s * 10 + n[i + 6] - '0';
  }
  return h * 3600 + m * 60 + s;
}

int c, h, arr[10000], ans = 86400;
string input;

int main() {
  cin >> c >> h;
  for(int i = 0; i < c + h; i++) {
    cin >> input;
    arr[i] = time_convert(input);
  }
  sort(arr, arr + c + h); // 소팅 안함
  for(int i = c + h - 1; i >= 0; i--) {
    ans -= arr[i + 1] - arr[i] > 40 || i + 1 == c + h ? 40 : arr[i + 1] - arr[i]; // 조건 잘못 적음 "> 40" 위치 오류
  }
  cout << ans;

  return 0;
}