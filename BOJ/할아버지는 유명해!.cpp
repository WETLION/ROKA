#include <iostream>
#include <algorithm>

// 5766번 할아버지는 유명해!

using namespace std;

struct node {
  int n, cnt;
};

int n, m, input, cmp;
node arr[10001];

bool comp(node a, node b) {
  return a.cnt == b.cnt ? a.n < b.n : a.cnt > b.cnt;
}

int main() {
  while(1) {
    cin >> n >> m;
    if(!n) break;
    for(int i = 0; i <= 10000; i++) {
      arr[i].cnt = 0;
      arr[i].n = i;
    }
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        cin >> input;
        arr[input].cnt++;
      }
    }
    sort(arr, arr + 10001, comp);
    cmp = arr[0].cnt;
    for(int i = 0; ; i++) {
      if(arr[i].cnt != cmp) {
        cmp = arr[i].cnt;
        for(; ; i++) {
          if(arr[i].cnt != cmp) break;
          cout << arr[i].n << " ";
        }
        break;
      }
    }
    cout << endl;
  }

  return 0;
} 