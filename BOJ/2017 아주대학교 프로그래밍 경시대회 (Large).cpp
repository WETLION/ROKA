#include <iostream>
#include <algorithm>

// 14593번 2017 아주대학교 프로그래밍 경시대회 (Large)

using namespace std;

struct node {
    int s, c, l, num;
};

bool cmp(node a, node b) {
    return a.s == b.s ? a.c == b.c ? a.l < b.l : a.c < b.c : a.s > b.s;
}

node arr[10000];
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].s >> arr[i].c >> arr[i].l;
        arr[i].num = i + 1;
    }
    sort(arr, arr + n, cmp);
    cout << arr[0].num;

    return 0;
}