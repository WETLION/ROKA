#include <iostream>
#include <vector>
#include <algorithm>

// 1557번 제곱 ㄴㄴ

using namespace std;

long long n, arr[50001], before;
vector<vector<long long>> v;

void recursion(long long now, int num, int start) {
  if(now > 2000000000) return;
  if(v.size() == num) v.push_back(vector<long long>());
  if(num) v[num].push_back(now);
  for(int i = start; i < v[0].size(); i++) {
    recursion(now * v[0][i], num + 1, i + 1);
  }
}

int main() {
  cin >> n;
  arr[0] = arr[1] = 1;
  v.push_back({4});
  for(int i = 4; i <= 45000; i = i + 2) arr[i] = 1;
  for(long long i = 3; i < 45000; i = i + 2) {
    if(arr[i]) continue;
    v[0].push_back(i * i);
    for(int j = i * 2; j < 45000; j = j + i) arr[j] = 1;
  }
  for(int i = 0; i < v[0].size(); i++) {
    recursion(v[0][i], 0, i + 1);
  }
  for(int i = 1; i < v.size(); i++) {
    sort(v[i].begin(), v[i].end()); // 초기 소수의 제곱수들의 집합 이후로는 재귀함수의 특성상 오름차순이 아닐 수 있음!! 
  }
  while(1) {
    int sum = 0;
    for(int j = 0; j < v.size(); j++) { // 만약 v의 vector 갯수만큼 다 도는 경우에는 j가 초과할 수 있음 
      int temp = 0;
      for(long long i: v[j]) {
        if(i > n) break;
        temp += n / i - before / i;
//				cout << n << " " << before << " " << j << " " << i << " " << n / i << " " << before / i << endl;
      }
      if(!temp) break;
      sum += temp * (j % 2 ? -1 : 1);
    }
    if(!sum) break;
    before = n;
    n += sum;
  }
  cout << n;
//	cin >> n;

  return 0;
} 