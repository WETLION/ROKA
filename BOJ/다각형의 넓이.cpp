#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

long long int arr[10001][2];

int main() {
  long long int n, plus = 0, minus = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  for (int i = 0; i < n; i++) {
    plus += arr[i][0] * arr[(i + 1) % n][1];
    minus += arr[i][1] * arr[(i + 1) % n][0];
  }
  printf("%.1f", round(5 * abs(plus - minus)) / 10);

  return 0;
}