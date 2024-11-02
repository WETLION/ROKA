#include <iostream>
#include <vector>
#include <algorithm> 

// 2428번 표절 

using namespace std;

long long n, ans, input;
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) {
    int location = upper_bound(v.begin(), v.end(), v[i] * 10 / 9) - v.begin();
    ans += location - i - 1;
  }
  cout << ans;

  return 0;
}