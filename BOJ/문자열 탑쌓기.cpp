#include <iostream>
#include <algorithm>

// 25643번 문자열 탑쌓기

using namespace std;

int n, m;
string before, now;

bool forward_chk(string cmp) {
  for(int j = m - cmp.size(), k = 0; j < m; j++, k++) {
    if(cmp[k] != before[j]) return 0;
  }
  return 1;
}

bool backward_chk(string cmp) {
  reverse(cmp.begin(), cmp.end());
  for(int j = 0; j < cmp.size(); j++) {
    if(cmp[j] != before[j]) return 0;
  }
  return 1;
}


bool forward() {
  string cmp;
  for(char i: now) {
    cmp += i;
    if(forward_chk(cmp)) return 1;
  }
  return 0;
} 

bool backward() {
  string cmp;
  for(int i = m - 1; i >= 0; i--) {
    cmp += now[i];
    if(backward_chk(cmp)) return 1;
  }
  return 0;
}

int main() {
  cin >> n >> m >> before;
  while(--n) {
    cin >> now;
    if(!forward() && !backward()) {
      cout << 0;
      return 0;
    }
    before = now;
  }
  cout << 1;

  return 0;
} 