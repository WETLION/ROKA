#include <iostream>

// 29751번 삼각형

using namespace std;

int w, h;

int main() {
  cin >> w >> h;
  cout.precision(1);
  cout << fixed;
  cout << (double)w * h / 2;

  return 0;
}