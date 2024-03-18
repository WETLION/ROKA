#include <iostream>
#include <vector>

// 1068번

using namespace std;

typedef struct {
  vector<int> v;
  int before;
} node;

node arr[51];
int cnt;

// void tree_delete(int n) {
//   if(!arr[n].v.size()) return;
//   for(int i=0; i<arr[n].v.size(); i++) {
//     tree_delete(arr[n].v[i]);
//   }
// }

void count_leaf(int n) {
  if (arr[n].v.empty()) {
    cnt++;
    return;
  }
  for (int i = 0; i < arr[n].v.size(); i++) {
    count_leaf(arr[n].v[i]);
  }
}

int main() {
  int n, temp, cut, root;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == -1) {
      root = i;
      continue;
    }
    arr[temp].v.push_back(i);
    arr[i].before = temp;
  }
  cin >> cut;
  if (cut == root) {
    cout << 0;
    return 0;
  }
  // tree_delete(cut);
  for (int i = 0; i < arr[arr[cut].before].v.size(); i++) {
    if (arr[arr[cut].before].v[i] == cut) {
      arr[arr[cut].before].v.erase(arr[arr[cut].before].v.begin() + i);
    }
  }
  count_leaf(root);
  cout << cnt;

  return 0;
}