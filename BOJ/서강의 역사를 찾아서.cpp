#include <iostream>

// 25177번 서강의 역사를 찾아서

using namespace std;

int n, m, arr_n[1001], input, ans;

int main() {
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> arr_n[i];
  }
  for(int i = 0; i < m; i++){
    cin >> input;
    if(i >= n) ans = max(input, ans);
    else ans = max(input - arr_n[i], ans);
  }
  cout << ans;

  return 0;
} 