#include <iostream>
#include <algorithm>

// 1740번 거듭제곱

using namespace std;

long long n;
__int128_t ans;
string output;

int main() {
  cin >> n;
  for(int i = 0; n; i++) {
    __int128_t pow = 1;
    if(n & 1) {
      for(int j = 0; j < i; j++) {
        pow *= 3;
      }
      ans += pow;
    }

    n >>= 1;
  }
  while(ans) {
    output += '0' + ans % 10;
    ans /= 10;
  }
  reverse(output.begin(), output.end());
  cout << output;

  return 0;
}