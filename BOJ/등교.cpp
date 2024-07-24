#include <iostream>

// 31962번 등교

using namespace std;

int n, x, s, t, Max = -1;

int main() {
  cin >> n >> x;
  for(int i = 1; i <= n; i++) {
    cin >> s >> t;
    if(s + t <= x && Max <= s) {
      Max = s;
    }
  }
  cout << Max;

  return 0;
}