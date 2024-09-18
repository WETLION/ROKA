#include <iostream>
#include <algorithm>

// 4159번 알래스카

using namespace std;

int n, arr[2000];

int main() {
  while(1) {
    int chk = 0;
    cin >> n;
    if(!n) break;
    for(int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 1; i < n; i++) {
      if(!chk && arr[i] - arr[i - 1] > 200) {
        cout <<  "IMPOSSIBLE" << endl;
        chk = 1;
      }
    }
    if(!chk) {
      if(1422 - arr[n - 1] > 100) cout << "IMPOSSIBLE" << endl;
      else cout << "POSSIBLE" << endl;
    }
  }


  return 0;
}