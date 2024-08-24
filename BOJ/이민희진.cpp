#include <iostream>
#include <vector>
#include <algorithm>

// 28064번 이민희진

using namespace std;

int n, ans, k_max, chk[100][100];
string input;
vector<string> v;

bool cmp(string a, string b) {
  return a.size() > b.size();
}

int make_ans(int i, int j, int k) {
  string t_f, t_b;
  for(int f = 0, b = v[i].size() - k; f < k; f++, b++) {
    if(v[j][f] != v[i][b]) return 0;
    t_f += v[j][f];
    t_b += v[i][b];
  }
  // cout << t_f << " " << t_b << " " << i << " " << j << endl;
  return 1;
}

int main() {
  cin >> n;
  for(int ii = 0; ii < n; ii++) {
    cin >> input;
    v.push_back(input);
    k_max = max(k_max, (int)input.size());
  }
  sort(v.begin(), v.end(), cmp);
  for(int k = 1; k <= k_max; k++) {
    for(int i = 0; i < n; i++) {
      if(v[i].size() < k) {
        n = i;
        continue;
      }
      for(int j = 0; j < n; j++) {
        if(i == j || chk[i][j]) continue;
        ans += chk[i][j] = chk[j][i] = make_ans(i, j, k);
      }
    }
  }
  cout << ans;

  return 0;
}