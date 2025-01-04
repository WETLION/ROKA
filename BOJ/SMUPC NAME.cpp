#include <iostream>
#include <algorithm>
#include <string>

// 31859번 SMUPC NAME

using namespace std;

int n, chk[30], cnt;
string str, ans;

int main() {
  cin >> n >> str;
  ans += to_string(1906 + n);
  for(char i: str) {
    if(!chk[i - 'a']) {
      chk[i - 'a'] = 1;
      ans += i;
    }
    else cnt++;
  }
  ans += to_string(cnt + 4);
  reverse(ans.begin(), ans.end());
  cout << "smupc_" << ans;
  cin >> n;

  return 0;
} 