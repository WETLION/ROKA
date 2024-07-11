#include <iostream>

// 2721번 삼각수의 합

using namespace std;

int T(int n) {
  return n * (n + 1) / 2;
}

int n, t;
long long ans;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    ans = 0;
    for(int i = 1; i <= n; i++) {
      ans += i * T(i + 1);
    }
    cout << ans << endl;
  }


  return 0;
}