#include <iostream>
#include <vector>

using namespace std;

vector<int> v[500005];

int arr[500005];

int main() {
  int n, m, f, b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    arr[i] = i;
    v[i].push_back(i);
  }
  for (int i = 1; i <= m; i++) {
    cin >> f >> b;
    if (arr[f] == arr[b]) {
      cout << i;
      return 0;
    }
    int in, out;
    if (arr[f] > arr[b]) {
      in = arr[b];
      out = arr[f];
    } else {
      in = arr[f];
      out = arr[b];
    }
    while (!v[out].empty()) {
      int temp = v[out].back();
      v[out].pop_back();
      v[in].push_back(temp);
      arr[temp] = in;
    }
    // for(int j=0; j<n; j++) {
    //   cout << arr[j];
    // }
    // cout << endl;
  }
  cout << 0;

  return 0;
}