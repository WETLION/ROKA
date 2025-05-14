#include <iostream>
#include <algorithm>
#include <vector>

// 16159번 전광판의 숫자

using namespace std;

string str[7];
int arr[10][7] = {{0, 12, 18, 18, 18, 12, 0}, {0, 4, 12, 4, 4, 4, 0}, {0, 30, 2, 30, 16, 30, 0}, {0, 28, 2, 4, 2, 28, 0}, {0, 4, 12, 20, 62, 4, 0}, {0, 30, 16, 28, 2, 18, 12}, {0, 16, 16, 30, 18, 30, 0}, {0, 30, 2, 4, 4, 4, 0}, {0, 30, 18, 30, 18, 30, 0}, {30, 18, 18, 30, 2, 2, 2}}, num[10], len;
vector<int> v, ans;

int isit_end() {
//	for(int i = len - 1; i >= 0; i--) cout << num[i] << " ";
	for(int i = len - 1; i > 0; i--) if(num[i - 1] < num[i]) return i - 1; // i--를 i++로 적는 실수 
	return -1;
}

bool isit_num(int array[], int chk) {
	for(int i = 0; i < 7; i++) if(arr[chk][i] != array[i]) return false;
	return true;
}

int split(int start) {
	int chk[7] = {};
	for(int i = 0; i < 7; i++) {
		for(int j = start; j < start + 6; j++) { // j++ 대신 i++ 적는 실수 
			chk[i] <<= 1;
			chk[i] |= str[i][j] == '1';
		}
//		cout << chk[i] << endl;
	}
//	cout << endl;
	for(int i = 0; i < 10; i++) if(isit_num(chk, i)) return i;
}

string change_bit_str(int num) {
	string ret;
	for(int i = 5; i >= 0; i--) ret.push_back('0' + ((num >> i) & 1));
	return ret;
}

int main() {
	for(int i = 0; i < 7; i++) cin >> str[i];
	len = str[0].size() / 6;
	for(int i = 0; i < len; i++) num[i] = split(i * 6); // i * 6을 시작점으로 안보냄 
//	cout << num[0];
	int start = isit_end(), chk = 0;
//	cout << start << " " << len; 
	if(start < 0) {
		cout << "The End";
		cin >> start;
		return 0;
	}
	// 무조건 맨 끝과 늘어나는 시작 지점의 숫자를 바꾼 후 나머지를 sort해서 붙였는데 그러면 나중 숫자가 안커질수도 있는 지점을 수정함 
	for(int i = 0; i < start; i++) ans.push_back(num[i]);
	for(int i = len - 1; i >= start; i--) { // start까지 다 넣어야하는데 안넣음 
		if(num[i] > num[start] && !chk) {
			ans.push_back(num[i]);
			chk = 1;
		}
		else v.push_back(num[i]);
	}
	sort(v.begin(), v.end());
	ans.insert(ans.end(), v.begin(), v.end());
//	for(int i: ans) cout << i << " ";
//	cout << endl;
	for(int i = 0; i < 7; i++) {
		for(int j = 0; j < len; j++) cout << change_bit_str(arr[ans[j]][i]);
		cout << endl;
	}
	cin >> start;

	return 0;
} 