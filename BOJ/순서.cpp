#include <iostream>
#include <vector>
#include <algorithm>

// 9011번 순서 

using namespace std;

int t, n, input;

bool find(vector<int> v, vector<int> vv) {
  vector<int> ans;
  for(int i: v) {
    if(vv.size() <= i) return 1; // i - 1 오류, 사실 -1이 필요 없었음(최소 0, 최대 n - 1), < -> <= 변경. size()는 1 크기 때문. 
    ans.push_back(vv[i]);
    vv.erase(vv.begin() + i);
  }
  reverse(ans.begin(), ans.end());
  for(int i: ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}

int main() {
  cin >> t;
  while(t--) {
    vector<int> v, vv;
    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> input;
      v.push_back(input);
      vv.push_back(i + 1);
    }
    reverse(v.begin(), v.end());
    if(find(v, vv)) cout << "IMPOSSIBLE" << endl;
  }

  return 0;
}