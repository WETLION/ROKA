#include <iostream>
#include <string>

// 29731번 2033년 밈 투표

using namespace std;

string chk[10] = {"give you up", "let you down", "run around and desert you", "make you cry", "say goodbye", "tell a lie and hurt you", "stop"}, input;
int n, isit;

int main() {
  cin >> n;
  getchar();
  while(n--) {
    getline(cin, input);
    isit = 0;
    for(int i = 0; i < 7; i++) {
      if(input == "Never gonna " + chk[i]) {
        isit = 1;
        break;
      }
    }
    if(!isit) {
      cout << "Yes";
      return 0;
    }
  }
  cout << "No";

  return 0;
}