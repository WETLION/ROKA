#include <iostream>

// 25628번 햄버거 만들기

using namespace std;

int a, b;

int main() {
  cin >> a >> b;
  if(a / 2 < b) cout << a / 2;
  else cout << b;

  return 0;
} 