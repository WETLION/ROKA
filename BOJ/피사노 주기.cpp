#include <iostream>

// 9471번 피사노 주기

using namespace std;

int p, n, m;

int main() {
  cin >> p;
  while(p--) {
    int cnt = 1, num = 1, before = 1;
    cin >> n >> m;
    if(m == 1) {
      cout << 1 << endl;
      continue;
    }
    while(num != 1 || before) {
      int temp = num;
      num = (num + before) % m;
      before = temp;
      cnt++;
      // cout << num << " " << before << endl;
    }
    cout << n << " " << cnt << endl;
  }

  return 0;
}