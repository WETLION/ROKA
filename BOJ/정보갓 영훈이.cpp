#include <iostream>
#include <vector>
#include <algorithm>

// 14843번 정보갓 영훈이

using namespace std;

int n, a, t, m, p;
double s, sum;

vector<double> v;

int main() {
  cout.precision(2);
  cout << fixed;
  cin >> n;
  while(n--) {
    cin >> s >> a >> t >> m;
    sum += s * (a + 1) * (t + m) / (4 * a * t);
  }
  cin >> p;
  for(int i = 0; i < p; i++) {
    cin >> s;
    v.push_back(s);
  }
  sort(v.begin(), v.end());
  int location = upper_bound(v.begin(), v.end(), sum) - v.begin();
  // cout << location << endl;
  if(((p + 1) * 85) % 100) p = (p + 1) * 85 / 100 + 1;
  else p = (p + 1) * 85 / 100;
  // cout << sum << " "<< p << " " << location << endl;
  cout << "The total score of Younghoon " << (p <= location ? "\"The God\" " : "") << "is " << sum << "."; // is 어쩜?

  return 0;
}