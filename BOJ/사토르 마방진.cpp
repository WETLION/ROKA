#include <iostream>

// 20112번 사토르 마방진

using namespace std;

int n;
string a, b, arr[101];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    a += arr[i];
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      b += arr[j][i];
    }
  }
  cout << (a == b ? "YES" : "NO");

  return 0;
} 