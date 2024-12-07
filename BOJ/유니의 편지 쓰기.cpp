#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// 28070번 유니의 편지 쓰기 

using namespace std;

struct node {
  int begin, end;
};

bool cmp(node a, node b) {
  return a.begin == b.begin ? a.end < b.end : a.begin < b.begin;
}

struct pq_cmp {
  bool operator() (const int &a, const int &b) {
      return a > b; // 오름차순 정렬
  }
};

int n, MAX, ans;
char str[100];
vector<node> v;
priority_queue<int, vector<int>, pq_cmp> pq;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    scanf(" %s", &str);
    int a_y = 0, a_m = 0, b_y = 0, b_m = 0;
    for(int j = 0; j < 4; j++) a_y = a_y * 10 + str[j] - '0';
    for(int j = 5; j < 7; j++) a_m = a_m * 10 + str[j] - '0';
    scanf(" %s", &str);
    // 밑의 for문 전부 범위 오류 
    for(int j = 0; j < 4; j++) b_y = b_y * 10 + str[j] - '0';
    for(int j = 5; j < 7; j++) b_m = b_m * 10 + str[j] - '0';
    v.push_back({a_y * 12 + a_m, b_y * 12 + b_m});
  }
  sort(v.begin(), v.end(), cmp);
  for(node i: v) {
    while(!pq.empty() && i.begin > pq.top()) pq.pop();
    pq.push(i.end);
    if(MAX < pq.size()) {
      ans = i.begin;
      MAX = pq.size();
    }
  }
  if(ans % 12) cout << ans / 12 << '-';
  else cout << ans / 12 - 1 << '-';
  ans %= 12;
  if(!ans) cout << 12;
  else if(ans < 10) cout << '0' << ans;
  else cout << ans;
  cin >> n;

  return 0;
}