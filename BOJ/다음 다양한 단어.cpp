#include <iostream>

// 16923번 다음 다양한 단어 

using namespace std;

int chk[30], ans[30];
string str;

int main() {
  cin >> str;
  for(char i: str) chk[i - 'a'] = 1;
  for(int i = 0; i < 26; i++) {
    if(!chk[i]) {
      cout << str << char('a' + i);
      cin >> str;
      return 0;
    }
  }
  for(int i = str.size() - 1; i > 0; i--) {
    if(str[i - 1] < str[i]) {
      ans[str[i - 1] - 'a'] = 1;
      for(int j = 0; j < i - 1; j++) {
        cout << str[j];
        ans[str[j] - 'a'] = 1;
      }
      for(int j = str[i - 1] - 'a'; j < 26; j++) {
        if(!ans[j]) {
          cout << char('a' + j);
          cin >> str;
          return 0;
        }
      }
    }
  }
  cout << -1;
  cin >> str;

  return 0;
}