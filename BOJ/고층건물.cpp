#include <algorithm>
#include <iostream>

// 1027 고층건물

using namespace std;

long long int arr[51], ans, n;

bool show_chk(long long int a, long long int b) {
  // double incline = (double)(arr[b] - arr[a]) / (b - a), start = arr[a];
  // cout << incline << endl;
  long long int y = (b - a) * (-arr[a]), comp = (arr[b] - arr[a]) * (-a);
  //식 수정, comp의 + arr[a] 삭제, y의 * (-arr[a])로 수정, long long으로 싹다
  //수정
  // cout << endl << "&&" << a << " " << b << endl;

  for (int i = a + 1; i < b; i++) {
    // start += incline;
    // cout << (arr[i] >= start) << " " << (y + (b - a) * arr[i] >= (comp +
    // (arr[b] - arr[a]) * i)) << endl; cout << y + (b - a) * arr[i] << " " <<
    // comp + (arr[b] - arr[a]) << endl; if(arr[i]>=start) return 1;
    if (y + (b - a) * arr[i] >= comp + (arr[b] - arr[a]) * i)
      return 1;
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++) {
    long long int cnt = 0;
    for (int j = i + 1; j < n; j++) {
      if (show_chk(i, j))
        continue;
      cnt++;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (show_chk(j, i))
        continue;
      cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans;

  return 0;
}