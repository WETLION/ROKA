#include <iostream>
#include <vector>

// 20116번 상자의 균형

using namespace std;
vector<long long> v;

long long n, l, input;
double sum;

int main() {
  cin >> n >> l;
  for(int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }
  for(int i = 1; i < n; i++) {
    sum += v.back();
    v.pop_back();
    // cout << v.back() - l << " " << sum / i << " " <<v.back() + l << endl;
    if(!(v.back() - l < sum / i && sum / i < v.back() + l)) {
      cout << "unstable";
      return 0;
    }
  }
  cout << "stable";

  return 0;
}