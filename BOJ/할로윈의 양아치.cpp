#include <iostream>
#include <vector>

using namespace std;

vector<int> v[30005];

int arr[30005], candy[30005], sum;

int main() {
  int n, m, k, f, b, candy_input;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> candy_input;
    arr[i] = i;
    candy[i] = candy_input;
    v[i].push_back(i);
    // cout << endl << i << " " << candy_input;
  }
  for (int i = 1; i <= m; i++) {
    cin >> f >> b;
    int in, out;
    if (arr[f] > arr[b]) {
      in = arr[b];
      out = arr[f];
    } else {
      in = arr[f];
      out = arr[b];
    }
    candy[in] += candy[out];
    while (!v[out].empty()) {
      int temp = v[out].back();
      v[out].pop_back();
      v[in].push_back(temp);
      arr[temp] = in;
    }
    // cout << endl;
    // for(int j=0; j<n; j++) {
    //   cout << arr[j] << " " << candy[j] << endl;
    // }
  }

  cout << sum;

  return 0;
}