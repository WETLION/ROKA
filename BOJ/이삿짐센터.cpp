#include <iostream>

// 16237번 이삿짐 센터 

using namespace std;

int a, b, c, d, ans;

int main() {
  cin >> a >> b >> c >> d >> ans;
  ans += d;
  ans += c;
  b -= c;
  a -= d;
  if(b > 0) { // b가 0이 아니면 무조건 들어가는데 그 부분을 까먹음 
    ans += b / 2;
    a -= b / 2;
    b %= 2;
    if(b) {
      ans++;
      a -= 3;
    }
  }
  else if(b < 0 && a) {
    a += b * 2;
  }
  if(a > 0) { // a가 0이 아니면 무조건 들어가는데 그 부분을 까먹음 
    ans += a / 5;
    a %= 5;
    if(a) ans++;
  }
  cout << ans;

  return 0;
}