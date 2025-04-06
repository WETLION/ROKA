#include <iostream>

// 28066번 타노스는 요세푸스가 밉다

using namespace std;

struct node{
	node(int number) {
		num = number;
	}
	node *next;
	int num;
};

node *start, *now;
int n, k;

int main() {
	cin >> n >> k;
	k--;
	start = now = new node(1);
	for(int i = 2; i <= n; i++) {
		node *temp = new node(i);
		now -> next = temp;
		now = temp;
	}
	now -> next = start; // 순환 리스트를 안만듬
	while(n - k > 0) {
		n -= k;
		now = start -> next;
		for(int i = 0; i < k; i++) {
			node *next = now -> next;
			delete now;
			now = next;
		}
		start = start -> next = now;
	}
	cout << start -> num;

	return 0;
}