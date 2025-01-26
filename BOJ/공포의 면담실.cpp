#include <iostream>
#include <algorithm>

// 30088번 공포의 면담실 

using namespace std;

long long n, m, arr[1000], input, sum, ans; // 정답 범위 오류(1,000,000명 이하의 직원 수에 1,000분 이하의 상담 시간을 가지므로 최악의 경우 500,500,000,000이므로 int 범위 초과) 

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> m;
    while(m--) {
      cin >> input;
      sum += input;
    }
    arr[i] = sum;
    sum = 0;
  }
  sort(arr, arr + n);
  for(int i = 0; i < n; i++) {
    sum += arr[i];
    ans += sum;
  }
  cout << ans;
//	cin >> n;

  return 0;
}