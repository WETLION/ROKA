#include <iostream>

// 14494번 다이나믹이 뭐예요?

using namespace std;

int n, m;
long long int arr[1001][1001];

long long int find(int a, int b) {
  // cout << a << " " << b << endl;
  if(arr[a][b]) return arr[a][b];
  return arr[a][b] = ((a > 1 ? find(a - 1, b) : 0) + (b > 1 ? find(a, b - 1) : 0) + (a > 1 && b > 1 ? find(a - 1, b - 1) : 0)) % 1000000007;
}

int main() {
  cin >> n >> m;
  arr[1][1] = 1;
  cout << find(n, m);

  return 0;
}