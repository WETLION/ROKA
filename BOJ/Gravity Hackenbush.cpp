#include <iostream>

// 25335번 Gravity Hackenbush

using namespace std;

int r, g, b, n, m, x, y;
string color;

int main() {
  cin >> n >> m;
  while(n--) {
    cin >> x >> y;
  }
  while(m--) {
    cin >> x >> y >> color;
    if(color == "R") r++;
    else if(color == "G") g++; 
    else b++;
  }
  if(g % 2) r++;
  cout << (r > b ? "jhnah917" : "jhnan917");

  return 0;
}