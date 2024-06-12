#include <iostream>

// 10808번 알파벳 개수

using namespace std;

int arr[30];
string input;

int main() {
  cin >> input;
  for(char i: input) {
    arr[i - 'a']++;
  }
  for(int i = 0; i < 26; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}