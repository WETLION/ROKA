#include <iostream>
#include <vector>

// 19942번 다이어트 

using namespace std;

struct node {
  int p, f, s, v, c;
};

int n, ans = -1;
node m, arr[20];
vector<int> ans_v;

bool isit_filled(node now) {
  return now.p >= m.p && now.f >= m.f && now.s >= m.s && now.v >= m.v;
}

void make_ans(int start, node now, vector<int> v) {
  if(isit_filled(now)) { // 조건 충족하고 이때의 가격 합이 정답과 같으면 dq에 push_front()하는 방식은, 조건 충족하고 이때의 가격 합이 정답과 같은 다른 조건에서 문제가 생김. 따라서 지속적으로 정답 vector를 추적하는 것이 맞음. 
    if(ans < 0 ? 1000000 : ans > now.c) {
      ans = now.c;
      ans_v = v;
    }
  }
  for(int i = start; i < n; i++) {
    v.push_back(i);
    make_ans(i + 1, {now.p + arr[i].p, now.f + arr[i].f, now.s + arr[i].s, now.v + arr[i].v, now.c + arr[i].c}, v);
    v.pop_back();
  }
}

int main() {
  cin >> n >> m.p >> m.f >> m.s >> m.v;
  for(int i = 0; i < n; i++) {
    cin >> arr[i].p >> arr[i].f >> arr[i].s >> arr[i].v >> arr[i].c;
  }
  make_ans(0, {0, 0, 0, 0, 0}, ans_v);
  cout << ans;
  if(ans >= 0){
    cout << endl;
    for(int i: ans_v) {
      cout << i + 1 << " ";
    }
  }

  return 0;
}