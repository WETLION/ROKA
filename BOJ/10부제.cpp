#include <iostream>

// 10797번 10부제

using namespace std;

int n, input, cnt;

int main() {
  cin >> n;
  for(int i = 0; i < 5; i++) {
    cin >> input;
    if(input == n) cnt++;
  }
  cout << cnt;

  return 0;
}