#include <algorithm>
#include <cstdio>
#include <vector>

// 16566번 수 찾기 문제
// cin cout을 싹다 scanf printf로 바꿔서 해결

using namespace std;

// vector와 array의 속도 비교
// vector와 erase 사용시 시간초과
// vector와 visit 사용시 통과
// array와 visit 사용시 통과

vector<int> v;
// int arr[4000001];
bool visit[4000001];

int main() {
  int n, m, k, input, location;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    // scanf("%d", &arr[i]);
    scanf("%d", &input);
    v.push_back(input);
  }
  // sort(arr, arr+n);
  sort(v.begin(), v.end());
  for (int i = 0; i < k; i++) {
    scanf("%d", &input);
    // location = upper_bound(arr, arr+n, input)-arr;
    location = upper_bound(v.begin(), v.end(), input) - v.begin();
    while (visit[location])
      location++;
    printf("%d\n", v[location]);
    visit[location] = 1;
    // v.erase(v.begin()+location);
  }

  return 0;
}