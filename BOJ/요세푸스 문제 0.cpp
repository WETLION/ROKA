#include <iostream>
#include <vector>
// #include <cstdlib>

// 11866번 요세푸스 문제 0

using namespace std;

vector<int> v;
int n, k, now;

int main() {
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    v.push_back(i);
  }
  cout << "<";
  k--;
  while(n) {
    now = (now + k) % n;
    n--;
    cout << v[now];
    if(n) cout << ", ";
    v.erase(v.begin() + now);
  }
  cout << ">";

  return 0;
}

// typedef struct _node {
//   struct _node *front, *back;
//   int num;
// }node;

// int n, k;
// node *start, *now;

// int main() {
//   cin >> n >> k;
//   for(int i = 1; i <= n; i++) {
//     node *ne = (node*)malloc(sizeof(node));
//     // cout << i << " ";
//     ne -> num = i;
//     // cout << i << endl;
//     if(i == 1) {
//       start = now = ne;
//     }
//     ne -> front = start;
//     ne -> back = now;
//     now -> front = ne;
//     now = ne;
//   }
//   // cout << "#" << endl;
//   cout << "<";
//   for(int i = 1; i <= n; i++) {
//     for(int j = 1; j < k; j++) {
//       start = start -> front;
//       // cout << now -> num << endl;
//     }
//     cout << start -> num;
//     if(i != n) {
//       cout << ", ";
//       start -> front -> back = start -> back;
//       start -> back -> front = start -> front;
//       // now = start;
//       start = start -> front;
//       // free(now);
//     }
//   }
//   cout << ">";

//   return 0;
// }