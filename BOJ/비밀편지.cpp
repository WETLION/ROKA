#include <iostream>

// 2596번 비밀편지

using namespace std;

int n;
string input, ans, arr[10] = {"000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010"};

int main() {
  cin >> n >> input;
  for(int i = 0; i < n; i++) {
    string split = "";
    int chk[10] = {}, all_chk = 1;
    for(int j = 6 * i; j < 6 * (i + 1); j++) {
      split += input[j];
    }
    // cout << split << endl;
    for(int j = 0; j < 8; j++) {
      for(int k = 0; k < 8; k++) {
        if(arr[k][j] != split[j]) chk[k]++;
      }
    }
    for(int j = 0; j < 8; j++) {
      if(chk[j] < 2) {
        ans += 'A' + j;
        all_chk = 0;
      }
    }
    if(all_chk) {
      cout << i + 1;
      return 0;
    }
  }
  cout << ans;

  return 0;
}