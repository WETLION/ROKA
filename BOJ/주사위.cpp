#include <algorithm>
#include <iostream>
#include <vector>

// 1041번 주사위

using namespace std;

long long int sum_arr[5] = {0, 0, 100000, 100000};
vector<long long int> va, vb, vc, vd, ve, vf;

void make_sum(int n, int target, long long int sum, vector<long long int> vv,
              int arr[]) {
  if (n == target) {
    sum_arr[target] = min(sum_arr[target], sum);
    return;
  }
  for (int i = 0; i < vv.size(); i++) {
    if (arr[i] == 1)
      continue;
    arr[i] = 1;
    make_sum(n + 1, target, sum + vv[i], vv, arr);
    arr[i] = 0;
  }
}

int main() {
  long long int n, a, b, c, d, e, f;
  int visit[2][6][10] = {};
  cin >> n >> a >> b >> c >> d >> e >> f;
  if (n == 1) {
    cout << a + b + c + d + e + f - max(a, max(b, max(c, max(d, max(e, f)))));
    return 0;
  }
  va.push_back(b);
  va.push_back(c);
  va.push_back(d);
  va.push_back(e);
  vb.push_back(a);
  vb.push_back(c);
  vb.push_back(d);
  vb.push_back(f);
  // vc.push_back(a);
  // vc.push_back(b);
  // vc.push_back(e);
  // vc.push_back(f);
  // vd.push_back(a);
  // vd.push_back(b);
  // vd.push_back(e);
  // vd.push_back(f);
  ve.push_back(a);
  ve.push_back(c);
  ve.push_back(d);
  ve.push_back(f);
  vf.push_back(b);
  vf.push_back(c);
  vf.push_back(d);
  vf.push_back(e);
  // make_sum(1, 3, a, va, visit[0][0]);
  // make_sum(1, 3, b, vb, visit[0][1]);
  // make_sum(1, 3, c, vc, visit[0][2]);
  // make_sum(1, 3, d, vd, visit[0][3]);
  // make_sum(1, 3, e, ve, visit[0][4]);
  // make_sum(1, 3, f, vf, visit[0][5]);
  // 3개의 경우 이렇게 찾으면 안됨.
  make_sum(1, 2, a, va, visit[1][0]);
  make_sum(1, 2, b, vb, visit[1][1]);
  // make_sum(1, 2, c, vc, visit[1][2]);
  // make_sum(1, 2, d, vd, visit[1][3]);
  make_sum(1, 2, e, ve, visit[1][4]);
  make_sum(1, 2, f, vf, visit[1][5]);

  sum_arr[3] = min(
      a + b + c,
      min(a + b + d,
          min(a + e + c,
              min(a + e + d,
                  min(f + b + c, min(f + b + d, min(f + e + c, f + e + d)))))));

  // cout << sum_arr[3] << " " << sum_arr[2] << " " << min(a, min(b, min(c,
  // min(d, min(e, f))))) << endl;
  cout << sum_arr[3] * 4 + sum_arr[2] * 4 * (2 * n - 3) +
              min(a, min(b, min(c, min(d, min(e, f))))) * (n - 2) * (5 * n - 6);

  return 0;
}