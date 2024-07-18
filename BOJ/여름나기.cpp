#include <iostream>

// 18130번 여름나기

using namespace std;

int n, ans_n;
long long ans, p, k, c, q, now;

int main() {
  cin >> n >> q;
  for(int i = 1; i <= n; i++) {
    cin >> p >> k >> c;
    now = p + (q % k == 0 ? ((q / k - 1) * (q / k)) / 2 : ((q / k) * (q / k + 1)) / 2) * c;
    if(!ans || ans > now) {
      ans_n = i;
      ans = now;
    }
  }
  cout << ans_n << " " << ans;

  return 0;
}