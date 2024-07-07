#include <iostream>
#include <vector>
#include <algorithm>

// 29198번 이번에는 C번이 문자열

using namespace std;

int n, m, k;
string input, ans;
vector<string> v;

int main() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    cin >> input;
    sort(input.begin(), input.end());
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < k; i++) {
    ans += v[i];
  }
  sort(ans.begin(), ans.end());
  cout << ans;

  return 0;
}