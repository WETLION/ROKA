#include <iostream>
#include <algorithm>

// 2687번 팩스 받기 

using namespace std;

int p, b;

int parse_hex(char now) {
	return '0' <= now && now <= '9' ? now - '0' : now - 'A' + 10;
}

int parse_byte(char a, char b) {
	return (parse_hex(a) << 4) + parse_hex(b);
}

string parse_hex_to_str(int num) {
	string str = "0123456789ABCDEF", ret;
	for(int i = 0; i < 2; i++) {
		ret.push_back(str[num % 16]);
		num /= 16;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	cin >> p;
	while(p--) {
		string ans, str, input;
		cin >> b;
		while(b > 0) { // 이 코드는 한 줄로 한번에 처리해야함. 
			cin >> input;
			str += input;
			b -= 40; // 80개의 16진수이므로 40개 byte씩 들어올것임. 
		}
		for(int i = 0; i < str.size(); ) {
			int count = parse_byte(str[i], str[i + 1]);
			i += 2;
			if(count >> 7) {
				string temp = parse_hex_to_str(parse_byte(str[i], str[i + 1]));
				i += 2;
				count &= 0b01111111;
				for(int j = 0; j < count + 3; j++) ans += temp;
			}
			else {
				for(int j = 0; j <= count; j++) {
					ans += parse_hex_to_str(parse_byte(str[i], str[i + 1]));
					i += 2;
				}
			}
		}
		cout << ans.size() / 2 << endl; // 출력 첫줄에 디코딩한 바이트 수를 출력해줘야함. 
		for(int i = 0; i < ans.size(); i++) {
			if(i && !(i % 80)) cout << endl;
			cout << ans[i];
		}
		if(p) cout << endl;
	}

	return 0;
}
