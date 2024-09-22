#include <iostream>
#include <cmath>

// 22973번 점프 숨바꼭질

using namespace std;

long long n;

int main() {
  cin >> n;
  if(n == 0) cout << 0;
  else if( n % 2 == 0) cout << -1;
  else cout << (int)log2(abs(n)) + 1;

  return 0;
}