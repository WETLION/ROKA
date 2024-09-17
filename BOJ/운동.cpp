#include <iostream>
#include <algorithm>

// 1173번 운동

using namespace std;

int N, m, M, T, R, now, ans;

int main() {
  cin >> N >> m >> M >> T >> R;
  now = m;
  if(m + T > M) {
    cout << -1;
    return 0;
  }
  while(N) {
    if(now + T <= M) {
      now += T;
      N--;
    }
    else now = max(m, now - R);
    ans++;
  }
  cout << ans;

  return 0;
}