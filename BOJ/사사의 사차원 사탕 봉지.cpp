#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

// 27968번 사사의 사차원 사탕 봉지

using namespace std;

int n, m;
long long int input, sum;
vector<long long int> v;

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    scanf("%lld", &input);
    v.push_back(sum += input);
  }
  while(n--) {
    scanf("%lld", &input);
    int location = lower_bound(v.begin(), v.end(), input) - v.begin();
    if(location == m) printf("Go away!\n");
    else printf("%d\n", location + 1);
  }

  return 0;
}