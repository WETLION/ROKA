#include <iostream>

// 23323번 황소 다마고치

using namespace std;

int t, i;
long long int n, m, chk, cnt;

int main() {
  cin >> t;
  while(t--) {
    cnt = 1;
    chk = 1;
    cin >> n >> m;
    while(n > 1) {
      chk /= 2;
      n /= 2;
      cnt++;
    }
    cnt += m;
    cout << cnt << endl;
  }

  return 0;
}