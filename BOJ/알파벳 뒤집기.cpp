#include <iostream>

// 30032번 알파벳 뒤집기 

using namespace std;

int n, d;
string str[10];

int main() {
  cin >> n >> d;
  for(int i = 0; i < n; i++) {
    cin >> str[i];
    for(int j = 0; j < n; j++) {
      if(d == 2) {
        if(str[i][j] == 'b') str[i][j] = 'd';
        else if(str[i][j] == 'd') str[i][j] = 'b';
        else if(str[i][j] == 'p') str[i][j] = 'q';
        else str[i][j] = 'p';
      }
      else {
        if(str[i][j] == 'b') str[i][j] = 'p';
        else if(str[i][j] == 'd') str[i][j] = 'q';
        else if(str[i][j] == 'p') str[i][j] = 'b';
        else str[i][j] = 'd';
      }
    }
  }
  for(int i = 0; i < n; i++) {
    cout << str[i] << endl;
  }

  return 0;
}