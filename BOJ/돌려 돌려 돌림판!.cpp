#include <iostream>

// 11504번 돌려 돌려 돌림판!

using namespace std;

int t, n, m, x, y, arr[200], input, comp, ans;

int main() {
  cin >> t;
  while(t--) {
    x = y = ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
      cin >> input;
      x = x * 10 + input;
    }
    for(int i = 0; i < m; i++) {
      cin >> input;
      y = y * 10 + input;
    }
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    for(int i = 0; i < n; i++) {
      comp = 0;
      for(int j = i, cnt = 0; cnt < m; cnt++, j = (j + 1) % n) {
        comp = comp * 10 + arr[j];
      }
      if(x <= comp && comp <= y) ans++; 
    }
    cout << ans << endl;
  }
//	cin >> n; 

  return 0;
}