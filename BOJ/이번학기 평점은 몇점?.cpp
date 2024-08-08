#include <iostream>
#include <cmath>

// 2942번 이번학기 평범은 몇점?

using namespace std;

int n, credit, sum;
double ans, s;
string input, score;

int main() {
  cin >> n;
  while(n--) {
    cin >> input >> credit >> score;
    if(score == "A+") s = 4.3;
    else if(score == "A0") s = 4.0;
    else if(score == "A-") s = 3.7;
    else if(score == "B+") s = 3.3;
    else if(score == "B0") s = 3.0;
    else if(score == "B-") s = 2.7;
    else if(score == "C+") s = 2.3;
    else if(score == "C0") s = 2.0;
    else if(score == "C-") s = 1.7;
    else if(score == "D+") s = 1.3;
    else if(score == "D0") s = 1.0;
    else if(score == "D-") s = 0.7;
    else s = 0;
    ans += credit * s;
    sum += credit;
  }
  cout.precision(2);
  cout << fixed;
  cout << round(ans / sum * 100) / 100;

  return 0;
}