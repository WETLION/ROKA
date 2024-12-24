#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 24938번 키트 분배하기

using namespace std;

int n, arr[200001];
long long sum, ans;
vector<int> v;

int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sum /= n;
  for(int i = 0; i < n; i++) if(arr[i] > sum) v.push_back(i);
  for(int i = 0; i < n - 1; i++) {
//		while(arr[i] < sum) {
//			vector<int>::iterator location = lower_bound(v.begin(), v.end(), i);
//			if(location == v.end()) location--;
//			else if(location != v.begin() && i - *(location - 1) < *location - i) location--;
//			int m = arr[*location] - sum;
//			// cout << *location << " " << arr[*location] << " " << m << endl;
//			if(arr[i] + m > sum) {
//				arr[*location] -= sum - arr[i]; // arr에 빼는게 아니고 갖다붙이는 실수, m - arr[i] -> sum - arr[i], 얼마를 가져다 썼는지로 변경
//				ans += (sum - arr[i]) * abs(*location - i); // m - arr[i] -> sum - arr[i], 얼마를 가져다 썼는지로 변경
//				arr[i] = sum;
//			} else {
//				arr[i] += m;
//				ans += m * abs(*location - i);
//				v.erase(location);
//			}
//		}
    ans += abs(sum - arr[i]);
    if(arr[i] > sum) arr[i + 1] += arr[i] - sum;
    else arr[i + 1] -= sum - arr[i];
  }
  cout << ans;
//	cin >> n;

  return 0;
}