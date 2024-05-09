#include <algorithm>
#include <iostream>

// 1058번 친구

using namespace std;

int n, arr[51][51], MAX;
char input;

int find_2_friends(int a, int b) {
  for (int i = 0; i < n; i++) {
    if (arr[b][i] && arr[a][i])
      return 1;
  }
  return 0;
}

int find_friends(int num) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == num)
      continue;
    sum += arr[num][i] ? 1 : find_2_friends(num, i);
  }
  return sum;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> input;
      arr[i][j] = input == 'Y';
    }
  }
  for (int i = 0; i < n; i++) {
    int sum = find_friends(i);
    MAX = max(sum, MAX);
  }
  cout << MAX;

  return 0;
}