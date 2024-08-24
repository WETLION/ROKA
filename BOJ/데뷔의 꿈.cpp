#include <iostream>
#include <algorithm>
#include <vector>

// 24465번 데뷔의 꿈

using namespace std;

int month[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
arr[13] = {19, 49, 79, 109, 140, 172, 203, 234, 265, 295, 326, 355, 365},
chk[12], n, m, d;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
  return a.first == b.first ? a.second > b.second : a.first < b.first;
}

int main() {
  for(int i = 0; i < 7; i++) {
    cin >> m >> d;
    int sum = month[m - 1] + d;
    // cout << sum << endl;
    int location = (lower_bound(arr, arr + 13, sum) - arr) % 12;
    // cout << location << endl;
    chk[location] = 1;
  }
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> m >> d;
    int sum = month[m - 1] + d;
    // cout << sum << endl;
    int location = (lower_bound(arr, arr + 13, sum) - arr) % 12;
    // cout << location << endl;
    if(!chk[location]) v.push_back(make_pair(sum, m == 2 && d == 29));
  }
  if(v.empty()) {
    cout << "ALL FAILED";
    return 0;
  }
  sort(v.begin(), v.end(), cmp);
  for(auto i: v) {
    if(i.second == 1) {
      cout << 2 << " " << 29 << endl;
      continue;
    }
    int location = lower_bound(month, month + 12, i.first) - month;
    cout << location << " " << i.first - month[location - 1] << endl;
  }

  return 0;
}