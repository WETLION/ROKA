#include <iostream>

// 2313번 보석 구매하기

using namespace std;

long long n, l, input, ans, ans_l[1001][2];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l;
    long long arr[1001][2] = {}, MAX = 0, a = 0, b = 0;
    for(int j = 0; j < l; j++) {
      cin >> input;
      if(!j) {
        MAX = arr[j][0] = input;
        arr[j][1] = 0;
        continue;
      }
      if(arr[j - 1][0] > 0) {
        arr[j][0] = arr[j - 1][0] + input;
        arr[j][1] = arr[j - 1][1];
        if(MAX < arr[j][0] || MAX == arr[j][0] && j - arr[j][1] < b - a) {
          MAX = arr[j][0];
          a = arr[j][1];
          b = j;
        }
      }
      else {
        arr[j][0] = input;
        arr[j][1] = j;
        if(MAX < input || MAX == input && b - a != 0) {
          MAX = input;
          a = b = j;
        }
      }
    }
    ans += MAX;
    ans_l[i][0] = a + 1;
    ans_l[i][1] = b + 1;
  }
  cout << ans << endl;
  for(int i = 0; i < n; i++) {
    cout << ans_l[i][0] << " " << ans_l[i][1] << endl;
  }

  return 0;
}