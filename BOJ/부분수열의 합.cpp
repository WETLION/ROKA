#include <iostream>

// 1182번 부분수열의 합

using namespace std;

int n, s, arr[30];

int count_of_sum(int num, int sum) {
  int cnt = sum == s && num;
  if (num != n) {
    for (int i = num; i < n; i++) {
      cnt += count_of_sum(i + 1, sum + arr[i]);
    }
  }
  return cnt;
}

int main() {
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cout << count_of_sum(0, 0);

  return 0;
}