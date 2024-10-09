#include <iostream>
#include <vector>
#include <algorithm>

// 29336번 월향, 비상

using namespace std;

vector<long long> v;
long long n, m, t, q, input, date, sum; // int 범위 이슈

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < m; i++) {
    cin >> t >> q;
    while(sum < q) {
      if(v.empty()) {
        cout << -1;
        return 0;
      }
      sum += v.back() + t;
      v.pop_back();
    }
  }
  for(long long i: v) {
    sum += i + t;
  }
  cout << sum;

  return 0;
}