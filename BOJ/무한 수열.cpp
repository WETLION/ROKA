#include <algorithm>
#include <iostream>
#include <map>

// 1351번 무한 수열

using namespace std;
long long int n, p, q;

map<long long int, long long int> m;

long long int find(long long int num) {
  // cout << num << endl;
  if (m.find(num) != m.end())
    return m[num];
  long long int number = find(num / p) + find(num / q);
  m.insert({num, number});
  return number;
}

int main() {
  cin >> n >> p >> q;
  m.insert({0, 1});
  // cout << "#";
  cout << find(n);
  // cin >> n;

  return 0;
}