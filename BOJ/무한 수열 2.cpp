#include <algorithm>
#include <iostream>
#include <unordered_map>

// 1354번 무한 수열 2

using namespace std;
long long int n, p, q, x, y;

unordered_map<long long int, long long int> m;

long long int find(long long int num) {
  // cout << num << endl;
  if (num <= 0)
    return 1;
  if (m.find(num) != m.end())
    return m[num];
  long long int number = find(num / p - x) + find(num / q - y);
  m.insert({num, number});
  return number;
}

int main() {
  cin >> n >> p >> q >> x >> y;
  // cout << "#";
  cout << find(n);
  // cin >> n;

  return 0;
}