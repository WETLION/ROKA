#include <iostream>
#include <algorithm>

// 17828번 문자열 화폐

using namespace std;

int l, money;
string ans;

int main() {
  cin >> l >> money;
  if(l > money || money / 26 == l && money % 26 || money / 26 > l) {
    cout << "!";
    return 0;
  }
  while(l) {
    // cout << money << " " << l << endl;
    if(money - 26 >= l) {
      ans += 'Z';
      money -= 26;
    }
    else {
      ans += 'A' + money - l;
      money -= money - l + 1;
    }
    l--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans;

  return 0;
}