#include <algorithm>
#include <iostream>
#include <vector>

// 1449번 수리공 항승

using namespace std;

int n, l, input, num, cnt;
vector<int> v;

int main() {
  cin >> n >> l;
  l--;
  while (n--) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  while (num < v.size()) {
    num = upper_bound(v.begin(), v.end(), v[num] + l) - v.begin();
    cnt++;
  }
  cout << cnt;

  return 0;
}