#include <iostream>
#include <cmath>

// 1639번 행운의 티켓

using namespace std;

string str;
int len;

int main() {
  cin >> str;
  for(int i = 1; i <= str.length() / 2; i++) {
    for(int j = 0; j <= str.length() - i * 2; j++) {
      int a = 0, b = 0;
      for(int k = j; k < j + i; k++) {
        a += str[k] - '0';
        // cout << str[k];
      }
      for(int k = j + i; k < j + i * 2; k++) {
        b += str[k] - '0';
        // cout << str[k];
      }
      // cout << endl;
      if(a == b) {
        len = i * 2;
      }
    }
  }
  cout << len;

  return 0;
}