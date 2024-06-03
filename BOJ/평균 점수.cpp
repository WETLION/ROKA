#include <iostream>

// 10039번 평균 점수

using namespace std;

int input, sum;

int main() {
  for(int i = 0; i < 5; i++) {
    cin >> input;
    if(input < 40) input = 40;
    sum += input;
  }
  cout << sum / 5;

  return 0;
}