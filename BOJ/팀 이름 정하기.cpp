#include <iostream>

// 1296번 팀 이름 정하기

using namespace std;

int n, cnt;

int point(string green, string input) {
  int l = 0, o = 0, v = 0, e = 0;

  for (int i = 0; i < green.size(); i++) {
    if (green[i] == 'L')
      l++;
    else if (green[i] == 'O')
      o++;
    else if (green[i] == 'V')
      v++;
    else if (green[i] == 'E')
      e++;
  }
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == 'L')
      l++;
    else if (input[i] == 'O')
      o++;
    else if (input[i] == 'V')
      v++;
    else if (input[i] == 'E')
      e++;
  }

  return ((l + o) * (l + v) * (l + e) * (o + v) * (o + e) * (v + e)) % 100;
}

int main() {
  string green, input, ans;
  cin >> green >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    int now = point(green, input);
    if (cnt < now) {
      cnt = now;
      ans = input;
    } else if (cnt == now && (ans > input || ans.empty())) {
      ans = input;
    }
  }
  cout << ans;

  return 0;
}