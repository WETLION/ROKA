#include <iostream>
#include <vector>
#include <algorithm>

// 32185번 꿈 열정 나눔 

using namespace std;

struct node {
  int num, sum;
};

bool cmp(node a, node b) {
  return a.sum > b.sum;
}

int n, m, v, p, s, jae;
vector<node> V;

int main() {
  cin >> n >> m >> v >> p >> s;
  jae = v + p + s;
  for(int i = 1; i <= n; i++) {
    cin >> v >> p >> s;
    V.push_back({i, v + p + s});
  }
  sort(V.begin(), V.end(), cmp);
  cout << 0 << ' ';
  for(int i = 0, j = 0; i < n && j < m - 1; i++) {
    if(V[i].sum > jae) continue;
    cout << V[i].num << ' ';
    j++;
  }
  cin >> n;

  return 0;
}