#include <iostream>
#include <string>
#include <algorithm>

// 1357번 뒤집힌 덧셈

using namespace std;

string a, b, ans;

int main() {
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  ans = to_string(stoi(a) + stoi(b));
  reverse(ans.begin(), ans.end());
  cout << stoi(ans);

  return 0;
}