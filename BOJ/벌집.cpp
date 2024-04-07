#include <iostream>

using namespace std;

// 2292번 벌집

int main() {
  int n, cnt;
  cin >> n;
  for (int i = 0;; i++) {
    if (n <= 6 * i * (i + 1) / 2 + 1) {
      cout << i + 1;
      break;
    }
  }
  // cin >> n; // dev bug fix

  return 0;
}