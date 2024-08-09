#include <iostream>
#include <vector>
#include <algorithm>

// 26122번 가장 긴 막대 자석

using namespace std;

int n, sum, ans;
string input;
char before;
vector<int> v;

int main() {
  cin >> n >> input;
  for(char i: input) {
    if(before == i) {
      sum++;
    }
    else {
      if(before && before != i) {
        v.push_back(sum);
      }
      before = i;
      sum = 1;
    }
  }
  v.push_back(sum);
  if(v.size() == 1) cout << 0;
  else {
    for(int i = 0; i < v.size() - 1; i++) {
      ans = max(ans, min(v[i], v[i + 1]) * 2);
    }
    cout << ans;
  }

  return 0;
}