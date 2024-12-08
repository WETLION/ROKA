#include <iostream>
#include <algorithm>
#include <vector>

// 25287번 순열 정렬 

using namespace std;

int t, n, input;

int main() {
  cin >> t;
  while(t--) {
    cin >> n;
    vector<int> v[n];
    int before = 0;
    for(int i = 0; i < n; i++) {
      cin >> input;
      v[i].push_back(input);
      while(1) {
        int temp = n - v[i].back() + 1;
        if(temp == v[i].front()) break;
        v[i].push_back(temp);
      }
      sort(v[i].begin(), v[i].end());
    }
    for(int i = 0; i < n; i++) {
      int chk = 0;
      for(int j: v[i]) {
        if(j >= before) {
          before = j;
          chk = 1;
          break;
        }
      }
      if(!chk) {
        cout << "NO" << endl;
        before = -1;
        break;
      }
    }
    if(before != -1) cout << "YES" << endl;
  }
  cin >> t;

  return 0;
} 