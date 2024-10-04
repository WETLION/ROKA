#include <iostream>
#include <algorithm>

// 1834번 나머지와 몫이 같은 수

using namespace std;

int n;
__int128_t ans;
string str;

int main() {
  cin >> n;
  for(__int128_t i = 1; i < n; i++) {
    ans += i * n + i;
  }
  while(ans || str.empty()) {
    str += '0' + ans % 10;
    ans /= 10;
  }
  reverse(str.begin(), str.end());
  cout << str;

  return 0;
}