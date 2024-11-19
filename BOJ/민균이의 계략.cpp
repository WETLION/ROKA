#include <iostream>
#include <vector>
#include <algorithm>

// 11568번 민균이의 계략

using namespace std;

int n, input;
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    int location = lower_bound(v.begin(), v.end(), input) - v.begin();
    if(location == v.size()) v.push_back(input);
    else v[location] = input;
  }
  cout << v.size();
//	cin >> n;

  return 0;
} 