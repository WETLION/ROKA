#include <iostream>

// 12910번 사탕 나눠주기

using namespace std;

long long sum, p = 1, input, n, arr[100];

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    arr[input]++;
  }
  for(int i = 1; i <= 50; i++) {
    if(!arr[i]) break;
    p *= arr[i];
    sum += p;
  }
  cout << sum;

  return 0;
}