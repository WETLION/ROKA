#include <iostream>
#include <algorithm>

// 28116번 선택 정렬의 이동 거리

using namespace std;

struct node {
  int num, location;
};

int n, ans[1000000], temp, n_arr[1000000];

node arr[1000000];

bool cmp(node a, node b) {
  return a.num < b.num;
}

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> n_arr[i];
    arr[i].num = n_arr[i];
    arr[i].location = i;
  }
  sort(arr, arr + n, cmp);
  for(int i = 0; i < n; i++) {
//		cout << endl << n_arr[arr[i].location] << " " << arr[i].num << endl;
    ans[n_arr[i]] += arr[i].location - i;
    cout << ans[arr[i].num] + arr[i].location - i << " ";
//		cout << endl << arr[i].num << " " << arr[i].location << endl;
    temp = n_arr[i];
    n_arr[i] = n_arr[arr[i].location];
    n_arr[arr[i].location] = temp;
    arr[temp - 1].location = arr[i].location;
    arr[i].location = i;
  }
//	cin >> n;

  return 0;
}