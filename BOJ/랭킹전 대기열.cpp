#include <iostream>
#include <vector>
#include <algorithm>

// 20006번 랭킹전 대기열

using namespace std;

struct _node {
  int lev;
  string nickname;
};

struct node {
  int level;
  vector<_node> nv;
};

int p, m, l;
string n;
vector<node> v;

bool cmp(_node a, _node b) {
  return a.nickname < b.nickname;
}

bool insert(int lev, string str) {
  for(int i = 0; i < v.size(); i++) {
    if(v[i].level - 10 <= lev && lev <= v[i].level + 10) {
      if(v[i].nv.size() == m) continue;
      v[i].nv.push_back({lev, str});
      return 1;
    }
  }
  return 0;
}

int main() {
  cin >> p >> m;
  for(int i = 0; i < p; i++) {
    cin >> l >> n;
    if(insert(l, n)) continue;
    vector<_node> temp;
    temp.push_back({l, n});
    v.push_back({l, temp});
  }
  for(int i = 0; i < v.size(); i++) {
    if(v[i].nv.size() == m) cout << "Started!" << endl;
    else cout << "Waiting!" << endl;
    sort(v[i].nv.begin(), v[i].nv.end(), cmp);
    for(int j = 0; j < v[i].nv.size(); j++) cout << v[i].nv[j].lev << " " << v[i].nv[j].nickname << endl;
  }
  cin >> n; 

  return 0;
} 