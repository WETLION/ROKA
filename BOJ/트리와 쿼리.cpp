#include <iostream>
#include <vector>
#include <cstdio>

//15681번 트리와 쿼리 

using namespace std;

int n, r, q, a, b, chk[100001], cnt[100001];
vector<int> v[100001];

int find(int root) {
  int count = 1;
  for(int i: v[root]) {
    if(chk[i]) continue;
    chk[i] = 1;
    count += find(i);
  }
  return cnt[root] = count;
}

int main() {
//	cin >> n >> r >> q;
  scanf("%d%d%d", &n, &r, &q);
  for(int i = 0; i < n - 1; i++) {
//		cin >> a >> b;
  scanf("%d%d", &a, &b);
    v[a].push_back(b);
    v[b].push_back(a);
  }
  chk[r] = 1;
  find(r);
  for(int i = 0; i < q; i++) {
//		cin >> a;
    scanf("%d", &a);
//		cout << cnt[a] << endl;
    printf("%d\n", cnt[a]);
  }

  return 0;
}