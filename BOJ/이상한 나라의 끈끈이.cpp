#include <iostream>
#include <vector>
#include <algorithm>

// 32247번 이상한 나라의 끈끈이 

using namespace std;

struct node {
  int x, y, status;
};

bool cmp(node a, node b) {
  return a.x < b.x;
}

int n, m;
node input;
vector<node> v;

int main() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    cin >> input.status >> input.x >> input.y;
    v.push_back(input);
  }
  sort(v.begin(), v.end(), cmp);
  input = {0, 0, 0};
  for(node i: v) {
//		cout << input.x << " " << input.y << " " << i.x << " " << i.y << endl;
    if(i.status) {
      if(input.y - i.y + 1 > i.x - input.x) { // input.y와 i.y 위치 혼동 
        cout << "adios";
        cin >> n;
        return 0;
      }
      input.y = input.y - i.x + input.x;
      input.x = i.x;
    }
    else {
      if(i.y + 1 < input.y - i.x + input.x) i.y = input.y - i.x + input.x;
      else i.y++;
      input = i;
    }
  }
//	cout << input.x << " " << input.y << endl;
  if(input.y > n - input.x) cout << "adios"; 
  else cout << "stay";
  cin >> n;

  return 0;
}