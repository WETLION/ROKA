#include <iostream>
#include <vector>
#include <algorithm>

// 10211번 Maximum Subarray

using namespace std;

vector<int> v, vv, ans;
int t, n, input, MAX;

int main() {
  cin >> t;
  while(t--) {
    v.clear();
    vv.clear();
    MAX = -10000000;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> input;
      v.push_back(input);
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        vv[j] += v[i];
        MAX = max(vv[j], MAX);
      }
      vv.push_back(v[i]);
      MAX = max(v[i], MAX);
    }
    cout << MAX << endl;
  }

  return 0;
}