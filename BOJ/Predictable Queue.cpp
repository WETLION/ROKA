#include <iostream>
#include <algorithm>
#include <cstdio>

// 16510번 Predictable Queue

using namespace std;

int n, m, t, arr[200000];

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    scanf("%d", &t);
    if(i) arr[i] = arr[i - 1] + t;
    else arr[i] = t;
  }
  for(int i = 0; i < m; i++) {
    scanf("%d", &t);
    printf("%d\n", upper_bound(arr, arr + n, t) - arr);
  }
//	cin >> t;

  return 0;
}