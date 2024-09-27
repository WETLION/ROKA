#include <iostream>

// 14920번 3n+1 수열

using namespace std;

int n, cnt;

int main() {
  cin >> n;
  while(++cnt && n > 1) {
    if(n % 2) n = 3 * n + 1;
    else n /= 2;
  }
  cout << cnt;

  return 0;
}