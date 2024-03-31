#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

// 14003번 가장 긴 증가하는 부분 수열 5

using namespace std;

typedef struct {
  int num, score;
} node;

vector<int> vv;
vector<node> v;

int main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  int n, input, location;
  int chk = 0;
  // scanf("%d", &n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    // scanf("%d", &input);
    cin >> input;
    v.push_back({input, 0});
  }
  for (int i = 0; i < n; i++) {
    if (vv.empty() || vv.back() < v[i].num)
      vv.push_back(v[i].num);
    // location = upper_bound(arr, arr+n, input)-arr;
    location = lower_bound(vv.begin(), vv.end(), v[i].num) - vv.begin();
    vv[location] = v[i].num;
    v[i].score = location;
    // chk = location;
  }
  // for(int i=0; i<vv.size(); i++) {
  //   cout << vv[i] << " ";
  // }
  // cout << endl;
  cout << vv.size() << "\n";
  chk = vv.size() - 1;
  vv.clear();
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i].score == chk) {
      vv.push_back(v[i].num);
      chk--;
    }
  }
  for (int i = vv.size() - 1; i >= 0; i--) {
    cout << vv[i] << " ";
  }

  return 0;
}