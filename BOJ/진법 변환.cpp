#include <cmath>
#include <iostream>
#include <stack>

// 1112번 진법 변환

using namespace std;

stack<int> s;

int main() {
  int n, b, bb = 1;
  cin >> n >> b;
  if (n == 0) { // 예상치 못한 난관 1
    cout << 0;
    return 0;
  }
  if (n < 0 && b > 0) {
    cout << '-';
    n *= -1; // 예상치 못한 난관 2
  }
  if (b < 0) {
    b *= -1;
    bb = -1;
  }
  while (n != 0) {
    if (bb == -1 && n < 0) {
      for (int i = 0; i < b; i++) {
        if (-(n - i) % b == 0) {
          s.push(i);
          n -= i;
        }
      }
    } else
      s.push(n % b);
    n /= b;
    n *= bb;
    // cout << n << endl;
  }
  while (!s.empty()) {
    cout << s.top();
    s.pop();
  }

  return 0;
}