#include <algorithm>
#include <iostream>

// 2798번 블랙잭

using namespace std;

int n, m, arr[101], ans = 0;

void card_select(int num, int cnt, int start) {
  if (cnt == 3) {
    if (num <= m && num > ans) {
      ans = num;
    }
    return;
  }
  for (int i = start; i < n; i++) {
    card_select(num + arr[i], cnt + 1, i + 1);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  card_select(0, 0, 0);
  cout << ans;
}