#include <iostream>
#include <vector>

// 1124번 언더프라임

using namespace std;

bool prime[100001];
int arr[100001];
vector<int> v;

void make_prime(int b) {
  prime[0] = prime[1] = 1;
  for (int i = 2; i <= b; i++) {
    if (!prime[i]) {
      v.push_back(i);
      for (int j = i * 2; j <= b; j = j + i) {
        prime[j] = 1;
      }
    }
  }
}

int count(int num) {
  int cnt = 0;
  for (int j = 0; j < v.size(); j++) {
    if (num % v[j] == 0) {
      // cout << num << " " << v[j] << " " << (num%v[j]!=0) << endl;
      while (num % v[j] == 0 && num > 0) {
        // cout << num << endl;
        if (arr[num]) {
          // cout << num;
          cnt += arr[num];
          return cnt;
        }
        num /= v[j];
        cnt++;
      }
    }
  }
  return cnt;
}

int main() {
  int a, b, ans = 0;
  cin >> a >> b;
  make_prime(b);
  for (int i = a; i <= b; i++) {
    if (!prime[i])
      continue;
    // cout << i;
    int cnt = count(i);
    // cout << endl;
    arr[i] = cnt;
    // cout << cnt << endl;
    if (!prime[cnt])
      ans++;
  }
  cout << ans;

  return 0;
}