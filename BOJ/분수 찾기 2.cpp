#include <iostream>
#include <cmath>

// 27437번 분수 찾기 2 

using namespace std;

long long n, sq;

int main() {
  cin >> n;
  n *= 2;
  sq = sqrt(n);
  // 홀수는 윗방향, 짝수는 아랫방향(윗방향이 분자가 커지는 방향) 
  if(sq * (sq + 1) < n) sq++; // sq + 1 ~ sq + 2
  n /= 2;
  n = sq * (sq + 1) / 2 - n;
  if(sq % 2) {
    cout << n + 1 << '/' << sq - n;
  }
  else {
    cout << sq - n << '/' << n + 1;
  }

  return 0;
}