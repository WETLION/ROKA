#include <iostream>

// 4299번 AFC 윔블던

using namespace std;

int a, b, n;

int main() {
  cin >> a >> n;
  while (a >= b) {
    if (a - b == n) {
      cout << a << " " << b;
      return 0;
    }
    a--;
    b++;
  }
  cout << -1;

  return 0;
}