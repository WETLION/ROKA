#include <iostream>
#include <vector>

// 1816번 암호 키

using namespace std;

int n, arr[1000001];
long long input;
vector<int> v;

bool prime_check(long long num) {
  for(int i: v) {
    if(num % i == 0) return 0;
  }
  return 1;
}

int main() {
  arr[0] = arr[1] = 1;
  v.push_back(2);
  for(int i = 4; i <= 1000000; i = i + 2) {
    arr[i] = 1;
  }
  for(int i = 3; i < 1000000; i = i + 2) {
    if(arr[i]) continue;
    v.push_back(i);
    for(int j = i * 2; j < 1000000; j = j + i) {
      arr[i] = 1;
    }
  }
  cin >> n;
  while(n--) {
    cin >> input;
    cout << (prime_check(input) ? "YES" : "NO") << endl;
  }

  return 0;
}