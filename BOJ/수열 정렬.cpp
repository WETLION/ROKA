#include <algorithm>
#include <iostream>
#include <vector>

// 1015번 수열 정렬

using namespace std;

struct node {
  int num, place, ans;
};

vector<node> v;
int n, input;

bool cmp1(node a, node b) {
  return a.num == b.num ? a.place < b.place : a.num < b.num;
}

bool cmp2(node a, node b) { return a.place < b.place; }

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    v.push_back({input, i});
  }
  sort(v.begin(), v.end(), cmp1);
  for (int i = 0; i < n; i++) {
    v[i].ans = i;
  }
  sort(v.begin(), v.end(), cmp2);
  for (node i : v) {
    cout << i.ans << " ";
  }

  return 0;
}