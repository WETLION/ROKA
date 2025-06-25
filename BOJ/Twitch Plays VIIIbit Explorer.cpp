#include <iostream>
#include <queue>

// 25319번 Twitch Plays VIIIbit Explorer

using namespace std;

struct node {
	int x, y;
};

int n, m, s, cmp[30], c;
string str, ans;
queue<node> arr[30];
node location;

bool nickname_inside() {
	for(int i = 0; i < 26; i++) if(cmp[i] > arr[i].size()) return false; // 범위 지정 오류 
	return true;
}

string find_map(node start, node fin) {
	string ret;
	while(start.x > fin.x) {
		ret += "L";
		start.x--;
	}
	while(start.x < fin.x) {
		ret += "R";
		start.x++;
	}
	while(start.y > fin.y) {
		ret += "U";
		start.y--;
	}
	while(start.y < fin.y) {
		ret += "D";
		start.y++;
	}
	return ret;
}

int main() {
	cin >> n >> m >> s;
	for(int i = 0; i < n; i++) {
		cin >> str;
		for(int j = 0; j < m; j++) arr[str[j] - 'a'].push({j, i});
	}
	cin >> str;
	for(char i: str) cmp[i - 'a']++;
	while(nickname_inside()) {
		c++;
		for(char i: str) {
			node now = arr[i - 'a'].front();
			arr[i - 'a'].pop();
			ans += find_map(location, now) + "P";
			location = now;
		}
	}
	ans += find_map(location, {m - 1, n - 1});
	cout << c << " " << ans.size() << endl << ans;

	return 0;
}
