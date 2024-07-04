#include <iostream>

// 17362번 수학은 체육과목 입니다 2

using namespace std;

int n;

int main() {
  cin >> n;
  n %= 8;
  if(n == 1) cout << 1;
  else if(n == 2 || n == 0) cout << 2;
  else if(n == 3 || n == 7) cout << 3;
  else if(n == 4 || n == 6) cout << 4;
  else cout << 5;

  return 0;
}