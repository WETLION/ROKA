#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1001][3], price[1001][3], n, total_price;

int make_price(int num, int color) {
  if (num == n - 1)
    return arr[num][color];
  if (price[num][color]) {
    // cout << "#########" << endl;
    return price[num][color];
  }
  vector<int> v;
  for (int i = 0; i < 3; i++) {
    if (i != color)
      v.push_back(i);
  }
  return price[num][color] = min(arr[num][color] + make_price(num + 1, v[0]),
                                 arr[num][color] + make_price(num + 1, v[1]));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  total_price = min(make_price(0, 0), min(make_price(0, 1), make_price(0, 2)));
  cout << total_price;

  return 0;
}