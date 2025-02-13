#include <iostream>
#include <vector>
#include <algorithm>

// 2332번 지회

using namespace std;

struct node {
  int damage, location;
};

bool cmp(node a, node b) {
  return a.damage < b.damage;
}

int n, chk[50000], cnt, now;
vector<node> v;
vector<int> ans;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> chk[i];
    v.push_back({chk[i], i});
  }
  sort(v.begin(), v.end(), cmp);
  while(cnt < n) {
    node explove = v.back();
    v.pop_back(); // pop을 안해버림 
    if(!chk[explove.location]) continue;
    cnt++;
    ans.push_back(explove.location); // 정답은 지뢰의 위치 
    chk[explove.location] = 0; 
//		cout << "#" << explove.damage << " " << explove.location << endl;
    now = explove.damage;
    for(int i = explove.location + 1; i < n; i++) {
      if(now <= chk[i] || !chk[i]) break;
      cnt++;
      now = chk[i];
//			cout << "@" << now << " " << i << endl;
      chk[i] = 0; // 방문 위치 표기 안함 
    }
    now = explove.damage;
    for(int i = explove.location - 1; i >= 0; i--) {
      if(now <= chk[i] || !chk[i]) break;
      cnt++;
      now = chk[i];
//			cout << "@" << now << " " << i << endl;
      chk[i] = 0; // 방문 위치 표기 안함 
    }
  }
  sort(ans.begin(), ans.end()); // 정답은 지뢰의 위치의 오름차순 
  for(int i: ans) {
    cout << i + 1 << endl;
  }
  cin >> n;

  return 0;
}