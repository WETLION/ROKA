#include <iostream>

// 19698번 헛간 청약

using namespace std;

int n, w, h, l;

int main() {
  cin >> n >> w >> h >> l;
  cout << ((w / l) * (h / l) > n ? n : (w / l) * (h / l));

  return 0;
}