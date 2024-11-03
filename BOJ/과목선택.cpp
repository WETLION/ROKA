#include <iostream>
#include <algorithm>

// 11948번 과목선택

using namespace std;

int input, a = 100, ans;

int main() {
  for(int i = 0; i < 4; i++) {
    cin >> input;
    a = min(input, a);
    ans += input;
  }
  ans -= a;
  a = 0;
  for(int i = 0; i < 2; i++) {
    cin >> input;
    a = max(input, a);
  }
  cout << ans + a;

  return 0;
} 