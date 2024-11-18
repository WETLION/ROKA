#include <iostream>

// 1669번 멍멍이 쓰다듬기

using namespace std;

int a, b, n;
long long sum;

int main() {
  cin >> a >> b;
  n = b - a;
  if(!n) {
    cout << 0;
    return 0;
  }
  for(long long i = 1; i <= 65536; i++) {
    sum += i * 2;
    if(sum >= n) {
      if(sum - n >= i) {
        cout << i * 2 - 1;
        break;
      }
      else cout << i * 2;
      break;
    }
  }
  cin >> n;

  return 0;
}