#include <iostream>
#include <algorithm>

// 26711번 A+B

using namespace std;

string a, b;

int main() {
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  if(b.size() < a.size()) {
    b.resize(a.size(), '0');
  } 
  else if(b.size() > a.size()) {
    a.resize(b.size(), '0');
  }
  bool chk = 0;
  for(int i = 0; i < a.size(); i++) {
    int b_num = a[i] + b[i] - '0' * 2 + chk;
    chk = 0;
    if(b_num >= 10) {
      chk = 1;
      b_num -= 10;
    }
    a[i] = b_num + '0';
  }
  if(chk) {
    a.resize(a.size() + 1);
    a[a.size() - 1] = '1';
  }
  reverse(a.begin(), a.end());
  cout << a;

  return 0;
}