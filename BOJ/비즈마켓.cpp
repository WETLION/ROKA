#include <iostream>
#include <vector>
#include <algorithm>

// 25045번 비즈마켓

using namespace std;

int n, m, cnt, a_cnt;
vector<long long> a, b;
long long input, ans;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> input;
    a.push_back(input);
  }
  for(int i = 0; i < m; i++) {
    cin >> input;
    b.push_back(input);
  }
  sort(a.begin(), a.end(), greater<long long>());
  sort(b.begin(), b.end());
  while(n < m--) {
    b.pop_back();
  }
  while(cnt <= m) {
    // cout << b[cnt] << " " << a[a_cnt] << endl;
    if(b[cnt] < a[a_cnt]) {
      ans += a[a_cnt++] - b[cnt];
    }
    cnt++;
  }
  cout << ans;

  return 0;
}