#include <iostream>

// 17207번 돌려막기

using namespace std;

string name[5] = {"Inseo", "Junsuk", "Jungwoo", "Jinwoo", "Youngki"};
int arr[2][5][5], ans;
long long user[5], Min = 99999999999999999;

int main() {
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 5; j++) {
      for(int k = 0; k < 5; k++) {
        cin >> arr[i][j][k];
      }
    }
  }
  for(int x = 0; x < 5; x++) {
    for(int y = 0; y < 5; y++) {
      for(int i = 0; i < 5; i++) {
        user[x] += arr[0][x][i] * arr[1][i][y];
      }
    }
  }
  for(int i = 0; i < 5; i++) {
    // cout << user[i] << endl;
    if(user[i] <= Min) {
      Min = user[i];
      ans = i;
    }
  }
  cout << name[ans];

  return 0;
}