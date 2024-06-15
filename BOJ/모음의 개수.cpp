#include <iostream>

// 10987번 모음의 개수

using namespace std;

string input;
int cnt;

int main() {
  cin >> input;
  for(char i: input) {
    if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
  }
  cout << cnt;

  return 0;
}