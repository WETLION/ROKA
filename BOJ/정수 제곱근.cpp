#include <iostream>
#include <cmath>

// 2417번 정수 제곱근

using namespace std;

unsigned long long n, ans;

int main() {
  cin >> n;
  ans = sqrt(n);
  if(ans * ans >= n) cout << ans;
  else cout << ans + 1;

  return 0;
}