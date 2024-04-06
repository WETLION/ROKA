#include <iostream>
#include <stack>

// 1252번 이진수 덧셈

using namespace std;

stack<int> sa, sb, s;
string a, b;
int p, chk;

int main() {
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    sa.push(a[i] - '0');
  }
  for (int i = 0; i < b.size(); i++) {
    sb.push(b[i] - '0');
  }
  while (!sa.empty() && !sb.empty()) {
    int na = sa.top(), nb = sb.top();
    sa.pop();
    sb.pop();
    if (na + nb + p > 1) {
      s.push(na + nb + p - 2);
      p = 1;
    } else {
      s.push(na + nb + p);
      p = 0;
    }
  }
  while (!sa.empty()) {
    if (sa.top() + p > 1) {
      s.push(sa.top() + p - 2);
      p = 1;
    } else {
      s.push(sa.top() + p);
      p = 0;
    }
    sa.pop();
  }
  while (!sb.empty()) {
    if (sb.top() + p > 1) {
      s.push(sb.top() + p - 2);
      p = 1;
    } else {
      s.push(sb.top() + p);
      p = 0;
    }
    sb.pop();
  }
  if (p == 1)
    s.push(1);

  while (!s.empty()) {
    if (s.top() == 0 && chk == 0) {
      s.pop();
      continue;
    }
    chk = 1;
    cout << s.top();
    s.pop();
  }
  if (chk == 0) {
    cout << 0;
  }

  return 0;
}