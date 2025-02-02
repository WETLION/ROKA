#include <iostream>
#include <vector>

// 32408번 대전 도시철도 2호선 

using namespace std;

vector<int> v[100001], vv;
long long n, chk[100001], ans, a, b;

int line_1(int now) {
//	cout <<"$" << now << endl;
  chk[now] = 1; // checksum 없음으로 인해 무한 루프 발생 
  if(now == n) {
    vv.push_back(now);
    return 1;
  }
  for(int i: v[now]) {
    if(!chk[i] && line_1(i)) {
      vv.push_back(now);
      return 1;
    }
  }
  return chk[now] = 0;
}

long long size(int now) {
  int cnt = 1;
  chk[now] = 2;
  for(int i: v[now]) {
    if(!chk[i]) cnt += size(i);
  }
  return cnt;
}

int main() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  line_1(1);
  n -= vv.size();
  for(int i: vv) {
//		cout << "#" << i << " ";
//		cout << "%" << n << " ";
    for(int j: v[i]) {
      if(chk[j]) continue;
      long long cnt = size(j);
      ans += cnt * (n -= cnt);
//			cout << "@" << cnt << endl;
    }

  }
  cout << ans;

  return 0;
} 