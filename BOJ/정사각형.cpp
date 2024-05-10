#include <algorithm>
#include <cmath>
#include <iostream>

// 1485번 정사각형

using namespace std;

struct node {
  int x, y;
};

int n;
node arr[4];

bool cmp(node a, node b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

bool diagonal_is_quadrature() {
  return (arr[2].y - arr[1].y) * (arr[3].y - arr[0].y) ==
         -(arr[2].x - arr[1].x) * (arr[3].x - arr[0].x);
}

bool diagonal_is_same() {
  return (int)pow(arr[2].x - arr[1].x, 2) + (int)pow(arr[2].y - arr[1].y, 2) ==
         (int)pow(arr[3].x - arr[0].x, 2) + (int)pow(arr[3].y - arr[0].y, 2);
}

int main() {
  cin >> n;
  while (n--) {
    for (int i = 0; i < 4; i++) {
      cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + 4, cmp);
    // for(int i = 0; i < 4; i++) {
    //   cout << arr[i].x << " " << arr[i].y << endl;
    // }
    if (diagonal_is_quadrature() && diagonal_is_same())
      cout << 1 << endl;
    else
      cout << 0 << endl;
  }

  return 0;
}