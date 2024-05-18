#include <algorithm>
#include <iostream>

// 1145번 적어도 대부분의 배수

using namespace std;

int arr[5];

int gcd(int a, int b) { return a % b != 0 ? gcd(b, a % b) : b; }

int main() {
  int ans = 999999999;
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      int ij = arr[i] * arr[j] / gcd(arr[i], arr[j]);
      for (int k = j + 1; k < 5; k++) {
        ans = min(ans, ij * arr[k] / gcd(ij, arr[k]));
      }
    }
  }
  cout << ans;

  return 0;
}