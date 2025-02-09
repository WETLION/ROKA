#include <iostream>

// 23321번 홍익 댄스파티 

using namespace std;

string str[5], ans[2] = {".omln", "owln."}; // omln 실수 

int main() {
    for(int i = 0; i < 5; i++) {
      cin >> str[i];
  }
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < str[0].size(); j++) {
      if(str[1][j] == '.') cout << str[i][j];
      else cout << ans[str[0][j] == '.'][i];
    }
    cout << endl;
  }
  cin >> str[0];

    return 0;
} 