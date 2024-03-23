#include <algorithm>
#include <iostream>
#include <vector>

// 1920번 수 찾기 문제

using namespace std;

vector<int> v;

bool search(int l, int r, int n) {
  int m = (l + r) / 2;
  if (v[m] == n)
    return 1;
  if (l == r)
    return 0;
  return v[m] < n ? search(m + 1, r, n) : search(l, m - 1, n);
}

bool search_2(int l, int r, int n) {
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (v[m] == n)
      return 1;
    v[m] < n ? l = m + 1 : r = m - 1;
  }
  return 0;
}

int main() {
  int n, m, input;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &input);
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &input);
    // printf("%d\n", search(0, v.size()-1, input)) // -> 시간초과 남.
    printf("%d\n", binary_search(v.begin(), v.end(), input));
  }

  return 0;
}