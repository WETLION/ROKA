#include <iostream>
#include <algorithm>

// 1333번 부재중 전화 

using namespace std;

int n, l, d, ans;

int main() {
  cin >> n >> l >> d;
  ans = d;
  for(int i = 1; i <= n; i++) {
    while(ans < l * i + 5 * (i - 1)) ans += d;
    if(l * i + 5 * (i - 1) <= ans && ans < l * i + 5 * i) break;
  }
  cout << ans;
//	cin >> n;

  return 0;
}