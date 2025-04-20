#include <iostream>
#include <algorithm>

// 2591번 숫자카드 

using namespace std;

int arr[50], cnt[50] = {1, 1};
string str;

int main() {
	cin >> str;
	if(str.front() == '0') { // 맨 앞이 0인 경우는 거르지 못함. 
		cout << 0;
		return 0;
	}
	reverse(str.begin(), str.end());
	for(int i = 0; i < str.size(); i++) arr[i] = str[i] - '0';
	for(int i = 1; i < str.size(); i++) {
		if(!arr[i - 1]) { // 10 20 30은 따로 걸러야함. 
			if(arr[i] > 3 || !arr[i]) {
				cout << 0;
				return 0;
			}
			cnt[i + 2] = cnt[i + 1] = cnt[i]; // 연산자 대입 순서 오류 
			i++;
		}
		else if(!arr[i] || arr[i - 1] + arr[i] * 10 > 34) cnt[i + 1] = cnt[i];
		else cnt[i + 1] = cnt[i] + cnt[i - 1];
	}
	cout << cnt[str.size()];
	cin >> str;

	return 0;
}