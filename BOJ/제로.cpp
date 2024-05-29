#include <iostream>
#include <vector>

// 10773번 제로

using namespace std;

int n, input, sum;
vector<int> v;

int main() {
  cin >> n;
  while(n--) {
    cin >> input;
    if(!input) v.pop_back();
    else v.push_back(input);
  }
  for(int i: v) {
    sum += i;
  }
  cout << sum;

  return 0;
}