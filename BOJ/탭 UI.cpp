#include <iostream>
#include <cstdio>

// 29156번 탭 UI

using namespace std;

int n, l, sum[100001], arr[100001], q, input, make;

int main() {
  cin >> n;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    sum[i] = make += arr[i];
  }
  cin >> l >> q;
  if(l >= make) {
    for(int i = 0; i < q; i++) {
      scanf("%d", &input);
      printf("%.2lf\n", 0.0);
    }
    return 0;
  }
  for(int i = 0; i < q; i++) {
    scanf("%d", &input);
//		cout << "#" << make * 2 - sum[input] * 2 + arr[input] << endl;
    if(make * 2 - sum[input] * 2 + arr[input] <= l) printf("%.2lf\n", (double)make - l);
    else if(sum[input] * 2 - arr[input] - l < 0) printf("%.2lf\n", 0.0);
    else printf("%.2lf\n", (double)sum[input] - (double)arr[input] / 2 - (double)l / 2);
  }
//	cin >> n;

  return 0;
}