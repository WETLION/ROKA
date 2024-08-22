#include <iostream>

// 30045번 ZOAC 6

using namespace std;

int n, ans;
string input;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    for(int j = 1; j < input.size(); j++) {
      if(input[j - 1] == '0' && input[j] == '1' || input[j - 1] == 'O' && input[j] == 'I') {
        ans++;
        break;
      }
    }
  }
  cout << ans;

  return 0;
}