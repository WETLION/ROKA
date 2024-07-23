#include <iostream>
#include <algorithm>

// 2455번 지능형 기차

int sum, ans, a, b;

using namespace std;

int main() {
  for(int i = 0; i < 4; i++) {
    cin >> a >> b;
    sum = sum - a + b;
    ans = max(ans, sum);
  }
  cout << ans;

  return 0;
}