#include <iostream>
#include <deque>

// 24524번 아름다운 문자열 

using namespace std;

string s, t;
deque<int> dq[30];
int ans;

int main() {
  cin >> s >> t;
  for(int i = 0; i < s.size(); i++) {
    dq[s[i] - 'a'].push_back(i);
  }
  while(1) {
    for(int i = 0; i < t.size(); i++) {
      if(dq[t[i] - 'a'].empty()) {
        cout << ans;
//				cin >> s;
        return 0;
      }
      int temp = dq[t[i] - 'a'].front();
      dq[t[i] - 'a'].pop_front();
      if(i == t.size() - 1) break;
      while(!dq[t[i + 1] - 'a'].empty() && dq[t[i + 1] - 'a'].front() < temp) dq[t[i + 1] - 'a'].pop_front();
    }
    ans++;
  }

  return 0;
}