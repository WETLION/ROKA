#include <iostream>
#include <algorithm>
#include <cmath>

// 1198번 삼각형으로 자르기 

using namespace std;

int n,  x[40], y[40], ans;

int triangle(int a, int b, int c) {
  return abs((max(x[a], max(x[b], x[c])) - min(x[a], min(x[b], x[c]))) * (max(y[a], max(y[b], y[c])) - min(y[a], min(y[b], y[c])))) * 2 - (abs((x[c] - x[b]) * (y[c] - y[b])) + abs((x[a] - x[c]) * (y[a] - y[c])) + abs((x[a] - x[b]) * (y[a] - y[b]))); // y축 차이를 안구하고 ,를 찍어버림, / 2를 까먹음 
}

int main() {
  cout << fixed;
  cout.precision(1);
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
  }
  for(int i = 0; i < n - 2; i++) {
    for(int j = i + 1; j < n - 1; j++) {
      for(int k = j + 1; k < n; k++) {
        ans = max(ans, triangle(i, j, k));
      }
    }
  }
  cout << ans / 2;
  if(ans % 2) cout << ".5";
  else cout << ".0"; 

  return 0;
}