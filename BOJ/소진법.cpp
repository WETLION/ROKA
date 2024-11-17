#include <iostream>
#include <vector>
#include <algorithm>

// 4839번 소진법 

using namespace std;

long long n, arr[50], sum = 1, chk;
vector<long long> times, v;

int main() {
  for(int i = 4; i <= 50; i = i + 2) arr[i] = 1;
  v.push_back(2);
  for(int i = 3; i < 50; i = i + 2) {
    if(arr[i]) continue;
    v.push_back(i);
    for(int j = i * 2; j < 50; j = j + i) arr[j] = 1;
  }
  times.push_back(sum);
  for(long long i: v) {
    sum *= i;
    times.push_back(sum);
  }
  reverse(times.begin(), times.end());
  while(1) {
    cin >> n;
    if(!n) break;
    chk = 0;
    long long temp = n;
    vector<long long> ans;
    for(long long i: times) {
      if(chk || i <= n) {
        chk = 1;
        ans.push_back(n / i);
        n %= i;
      }
    }
    reverse(ans.begin(), ans.end());
    cout << temp << " = ";
    for(int i = 0; i < ans.size(); i++) {
      if(!ans[i]) continue;
      cout << ans[i];
      for(int j = 0; j < i; j++) {
        cout << "*" << v[j];
      }
      if(i != ans.size() - 1) cout << " + ";
    }
    cout << endl;
  }

  return 0;
}