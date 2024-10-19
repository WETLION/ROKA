#include <iostream>
#include <vector>
#include <algorithm>

// 29891번 체크포인트 달리기 

using namespace std;

int n, k, input;
long long ans;
vector<long long> m, p;

int main() {
  cin >> n >> k;
  for(int i = 0; i < n; i++) {
    cin >> input;
    if(input < 0) m.push_back(input);
    else p.push_back(input);
  }
  sort(m.begin(), m.end(), greater<int>());
  sort(p.begin(), p.end());
  while(m.size() >= k) {
    ans += m.back() * -2; // 제일 큰 것부터 찍고 와야함(원래 m[m.size() - k]) 
    for(int i = 0; i < k; i++) m.pop_back();
  }
  if(!m.empty()) ans += m.back() * -2; // back이 아니고 front 사용했음 
  while(p.size() >= k) {
    ans += p.back() * 2; // 제일 큰 것부터 찍고 와야함(원래 p[p.size() - k]) 
    for(int i = 0; i < k; i++) p.pop_back();
  }
  if(!p.empty()) ans += p.back() * 2; // back이 아니고 front 사용했음 
  cout << ans;

  return 0;
}