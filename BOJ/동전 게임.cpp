#include <iostream>

// 2684번 동전 게임

using namespace std;

int t;
string str, arr[10] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

int main() {
  cin >> t;
  while(t--) {
    int ans[10] = {};
    cin >> str;
    for(int i = 0; i < 38; i++) {
      string temp;
      for(int j = 0; j < 3; j++) {
        temp += str[i + j];
      }
      for(int j = 0; j < 8; j++) {
        if(arr[j] == temp) ans[j]++;
      }
    }
    for(int i = 0; i < 8; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}