#include <iostream>

// 23252번 블록

using namespace std;

int t, a, b, c;

int main() {
  cin >> t;
  while(t--) {
    cin >> a >> b >> c;
    if(b % 2) {
      if(a > 0 && c > 0) {
        a--;
        b = 0;
        c--;
      }
      else if(a > 1) {
        a -= 2;
        b = 0;
      }
    }
    c -= a;
    if(c < 0) {
      a = -c;
      c = 0;
    }
    else {
      a = 0;
    }
    if(c || a % 2 || b % 2) cout << "No" << endl;
    else cout << "Yes" << endl; // 대소문자 틀림;
  }

  return 0;
}