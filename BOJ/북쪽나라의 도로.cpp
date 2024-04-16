#include <algorithm>
#include <iostream>
#include <vector>

// 1595번 북쪽나라의 도로

using namespace std;

struct node {
  int dest, len;
};

int f, b, input, cnt[10001], MAX_CITY, MIN_COUNT = 999999, visit[10001],
                                       MIN_CITY, ans;
vector<node> v[10001];
vector<int> arr;

void make_arr(int n, int len) {
  for (node i : v[n]) {
    if (visit[i.dest]) {
      ans = max(ans, len);
      continue;
    }
    visit[i.dest] = 1;
    make_arr(i.dest, len + i.len);
    visit[i.dest] = 0;
  }
}

int main() {
  while (cin >> f >> b) {
    cin >> input;
    v[f].push_back({b, input});
    v[b].push_back({f, input});
    cnt[f]++;
    cnt[b]++;
    MAX_CITY = max(max(f, b), MAX_CITY);
  }
  for (int i = 1; i <= MAX_CITY; i++) {
    if (MIN_COUNT > cnt[i]) {
      MIN_COUNT = cnt[i];
      arr.clear();
      arr.push_back(i);
    } else if (MIN_COUNT == cnt[i]) {
      arr.push_back(i);
    }
  }
  for (int i : arr) {
    visit[i] = 1;
    make_arr(i, 0);
    visit[i] = 0;
  }
  cout << ans;

  return 0;
}