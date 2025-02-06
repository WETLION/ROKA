#include <iostream>
#include <algorithm>

// 27162번 Yacht Dice

using namespace std;

int arr[10], input, chk[20], ans;
string str;

int main() {
  cin >> str;
  for(int i = 0; i < 3; i++) {
    cin >> input;
    arr[input]++;
  }
  for(int k = 0; k < 12; k++) {
    if(str[k] == 'Y') {
      if(k < 6) ans = max(ans, (k + 1) * (2 + arr[k + 1]));
      else {
        switch(k) {
          case 6:
            for(int i = 1; i < 7; i++) {
              if(arr[i] > 1) {
                ans = max(ans, i * 4); // four of kind는 i * 4인데 i * (arr[i] + 2)를 시전함
                break;
              }
            }
            break;
          case 7:
            for(int i = 1; i < 7; i++) {
              if(arr[i] == 2) {
                for(int j = 1; j < 7; j++) {
                  if(arr[j] == 1) {
                    ans = max(ans, max(i * 3 + j * 2, i * 2 + j * 3));
                    break;
                  }
                }
                break;
              }
              if(arr[i] == 3) {
                ans = max(ans, i * 3 + (i == 6 ? 5 : 6) * 2);
                break;
              }
            }
            break;
          case 8:
            if(!arr[6]) {
              int chk = 0;
              for(int i = 1; i < 6; i++) {
                if(arr[i] > 1) { // streight에서 1개 이상이면 안되는데 2개일때만 걸러냄
                  chk = 1;
                  break;
                }
              }
              if(!chk) ans = max(ans, 30);
            }
            break;
          case 9:
            if(!arr[1]) {
              int chk = 0;
              for(int i = 2; i < 7; i++) {
                if(arr[i] > 1) { // streight에서 1개 이상이면 안되는데 2개일때만 걸러냄
                  chk = 1;
                  break;
                }
              }
              if(!chk) ans = max(ans, 30);
            }
            break;
          case 10:
            for(int i = 1; i < 7; i++) {
              if(arr[i] == 3) {
                ans = max(ans, 50);
                break;
              }
            }
            break;
          default:
            int sum = 12;
            for(int i = 1; i < 7; i++) {
              if(arr[i]) sum += arr[i] * i;
            }
            ans = max(ans, sum);
        }
      }
    }
  }
  cout << ans;

  return 0;
} 