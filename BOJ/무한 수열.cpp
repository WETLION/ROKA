#include <algorithm>
#include <iostream>
#include <vector>

// 1351번 무한 수열

using namespace std;

struct node {
  int num, cnt;
};

vector<node> v;
long long int n, p, q;

bool cmp(node a, node b) { return a.cnt < b.cnt; }

int node_cmp(int a, int b) { return a == b ? 0 : a > b ? 1 : -1; }

long long int find_location(long long int l, long long int r,
                            long long int find) {
  if (l > r)
    return -1;
  long long int m = (l + r) / 2;
  int cmp = node_cmp(find, v[m].cnt);
  return cmp == 0   ? m
         : cmp == 1 ? find_location(m + 1, r, find)
                    : find_location(l, m - 1, find);
}

long long int find(long long int num) {
  long long int cmp = find_location(0, v.size() - 1, num);
  if (cmp != -1)
    return v[cmp].num;
  long long int v_num = find(num / p) + find(num / q);
  v.push_back({v_num, num});
  return v_num;
}

int main() {
  cin >> n >> p >> q;
  v.push_back({1, 0});
  cout << find(n);
  cin >> n;

  return 0;
}