#include <iostream>
#include <queue>

// 28236번 점심시간 레이스

using namespace std;

struct node {
  int x, y, num;
};

int n, m, k;
node input;
queue<node> q;

int main() {
  cin >> n >> m >> k;
  for(int i = 1; i <= k; i++) {
    input.num = i;
    cin >> input.y >> input.x;
    q.push(input);
  }
  while(!q.empty()) {
    node now = q.front();
    q.pop();
    if(now.x == m + 1) {
      if(now.y == 1) {
        cout << now.num;
        return 0;
      }
      now.y--;
    }
    else {
      now.x++;
    }
    q.push(now);
  }

  return 0;
}