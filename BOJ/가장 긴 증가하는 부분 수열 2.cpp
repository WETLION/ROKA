#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

// 12015번 가장 긴 증가하는 부분 수열 2

using namespace std;

vector<int> v, vv;
// int arr[1000001];

int main() {
  int n, input, location;
  // scanf("%d", &n);
  cin >> n;
  for (int i = 0; i < n; i++) {
    // scanf("%d", &arr[i]);
    cin >> input;
    v.push_back(input);
  }
  for (int i = 0; i < n; i++) {
    if (vv.empty() || vv.back() < v[i])
      vv.push_back(v[i]);
    // location = upper_bound(arr, arr+n, input)-arr;
    location = lower_bound(vv.begin(), vv.end(), v[i]) - vv.begin();
    vv[location] = v[i];
  }
  cout << vv.size();

  return 0;
}