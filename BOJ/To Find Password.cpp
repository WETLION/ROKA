#include <iostream>
#include <queue>

// 23977번 To Find Password

using namespace std;

struct cmp{
  bool operator()(const int &a, const int &b){
    return a < b;
  }
};

long long int k, n, input, before;
priority_queue<int, vector<int>, cmp> pq;

long long int gcd(long long int a, long long int b) {
  return a % b ? gcd(b, a % b) : b;
}

int main() {
  cin >> k >> n;
  for(int i = 0; i < n; i++) {
    cin >> input;
    pq.push(input);
  }
  while(!pq.empty()) {
    if(!before) {
      before = pq.top();
      pq.pop();
    }
    int now = pq.top();
    pq.pop();
    before = before * now / gcd(before, now);
  }
  cout << before - k;

  return 0;
}