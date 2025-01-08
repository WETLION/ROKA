#include <iostream>

// 14489번 치킨 두 마리(...) 

using namespace std;

int a, b, c; 

int main() {
  cin >> a >> b >> c;
  a += b;
  if(a < c * 2) cout << a;
  else cout << a - c * 2;

  return 0;
}