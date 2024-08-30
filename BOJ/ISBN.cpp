#include <iostream>

// 14626번 ISBN

using namespace std;

string input;
int sum, mod = 1, save, ans;

int main() {
  cin >> input;
  for(int i = 0; i < input.size() - 1; i++) {
    if(input[i] == '*') save = mod;
    else sum += (input[i] - '0') * mod;
    mod = (mod + 2) % 4;
  }
  sum += (input.back() - '0');
  for(int i = 0; i < 10; i++) {
    if((sum + i * save) % 10 == 0) ans = i;
  }
  cout << ans;

  return 0;
}