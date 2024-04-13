#include <algorithm>
#include <iostream>
#include <vector>

// 1456번 거의 소수

using namespace std;

bool arr[10000001] = {0, 0, 1};
vector<long long int> v;

void make_arr() {
  for (long long int i = 2 * 2; i <= 100000000000000 && i > 0; i = i * 2) {
    v.push_back(i);
  }
  // for(int i = 4; i <= 10000000; i = i + 2) {
  //   arr[i] = 1;
  // }
  for (__int128 i = 3; i <= 10000000; i = i + 2) {
    if (arr[i])
      continue;
    for (int j = i + i; j <= 10000000; j = j + i) {
      arr[j] = 1;
    }
    for (__int128 j = i * i; j <= 100000000000000 && j > 0; j = j * i) {
      v.push_back((long long int)j);
    }
  }
}

int main() {
  make_arr();
  sort(v.begin(), v.end());
  // cout << v.size() << endl;
  long long int a, b;
  cin >> a >> b;
  // cout << (lower_bound(v.begin(), v.end(), a) - v.begin()) << endl <<
  // (upper_bound(v.begin(), v.end(), b) - v.begin()) << endl;
  cout << (upper_bound(v.begin(), v.end(), b) - v.begin()) -
              (lower_bound(v.begin(), v.end(), a) - v.begin());

  return 0;
}