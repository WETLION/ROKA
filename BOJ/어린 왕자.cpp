#include <cmath>
#include <iostream>

// 1004번 어린 왕자

using namespace std;

struct node {
  int x, y, r;
};

int t, start_x, start_y, dest_x, dest_y, n;
node input;

int main() {
  cin >> t;
  while (t--) {
    int cnt = 0;
    cin >> start_x >> start_y >> dest_x >> dest_y;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int visit = 0;
      cin >> input.x >> input.y >> input.r;
      if ((int)pow(abs(input.x - start_x), 2) +
              (int)pow(abs(input.y - start_y), 2) <
          (int)pow(input.r, 2))
        visit++;
      if ((int)pow(abs(input.x - dest_x), 2) +
              (int)pow(abs(input.y - dest_y), 2) <
          (int)pow(input.r, 2))
        visit++;
      if (visit == 1)
        cnt++;
    }
    cout << cnt << endl;
  }

  return 0;
}