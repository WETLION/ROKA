#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// 18110번 solved.ac

using namespace std;

int n, input, ans;
vector<int> v;

int main() {
  cin >> n;
  if(!n) {
    cout << 0;
    return 0;
  }
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  int except = round((double)n * 0.15);
  // cout << except << endl;
  for(int i = except; i < n - except; i++) {
    // cout << i << endl;
    ans += v[i];
  }
  cout << (int)round((double)ans / (n - except * 2));

  return 0;
}