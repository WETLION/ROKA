#include <iostream>
#include <cmath>

// 31416번 가상 검증 기술

using namespace std;

int q, t_a, t_b, v_a, v_b, ans, i;

int main() {
  cin >> q;
  while(q--) {
    ans = 0;
    cin >> t_a >> t_b >> v_a >> v_b;
    ans += t_b * v_b;
    if(ans >= t_a * v_a) {
      cout << ans << endl;
      continue;
    }
    for(i = 1; i <= v_a; i++)
      if(t_a * i >= ans) break;
    v_a -= i;
    if(v_a % 2) {
      ans += ceil((double)v_a / 2) * t_a;
    }
    else {
      ans += t_a * v_a / 2 + t_a * i - ans;
    }

    cout << ans << endl;
  }

  return 0;
}