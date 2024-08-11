#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

// 4358번 생태학 

using namespace std;

string input, before;
int cnt, sum;
vector<string> v;

int main() {
  while(1) {
    getline(cin, input);
    if(cin.eof()) break;
    v.push_back(input);
  }
  sort(v.begin(), v.end());
  cout.precision(4);
  cout << fixed;
  for(string i: v) {
    if(before == i) cnt++;
    else {
      if(before != "") cout << before << " " << round((double)cnt / v.size() * 1000000) / 10000 << endl;
      before = i;
      cnt = 1;
    }
  }
  cout << before << " " << round((double)cnt / v.size() * 1000000) / 10000 << endl;

  return 0;
}