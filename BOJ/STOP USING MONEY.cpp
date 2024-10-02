#include <iostream>
#include <vector>
#include <algorithm>

// 14674번 STOP USING MONEY

using namespace std;

struct node {
  long long c, h, num;
};

int n, k;
node input;
vector<node> v;

bool cmp(node a, node b) {
  a.h *= b.c;
  b.h *= a.c;
  // cout << a.num << " " << a.h << " " << b.num << " " << b.h << endl;
  return a.h == b.h ? a.c == b.c ? a.num < b.num : a.c < b.c : a.h > b.h; // num 섞어 넣을수도..
}

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> input.num >> input.c >> input.h;
    v.push_back(input);
  }
  sort(v.begin(), v.end(), cmp);
  for(int i = 0; i < k; i++) {
    cout << v[i].num << endl;
  }

  return 0;
}