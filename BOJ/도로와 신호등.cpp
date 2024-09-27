#include <iostream>

// 2980번 도로와 신호등

using namespace std;

int n, l, d, r, g, ans, before;

int main() {
  cin >> n >> l;
  for(int i = 0; i < n; i++) {
    cin >> d >> r >> g;
    ans += d - before;
    if(ans % (r + g) < r) ans += r - ans % (r + g);
    before = d;
    // cout << ans << endl;
  }
  ans += l - d;
  cout << ans;

  return 0;
}