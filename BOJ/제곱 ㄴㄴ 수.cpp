#include <iostream>
#include <vector>

// 1016번 제곱 ㄴㄴ 수 

using namespace std;

long long n, m, arr[1000001], chk[1000001], ans;
vector<long long> v;

int main() {
    cin >> n >> m;
    arr[0] = arr[1] = 1;
    v.push_back(4);
    for(int i = 4; i <= 1000001; i = i + 2) arr[i] = 1;
    for(long long i = 3; i < 1000001; i = i + 2) {
        if(arr[i]) continue;
        v.push_back(i * i);
        for(int j = i * 2; j < 1000001; j = j + i) arr[j] = 1;
    }
    ans = m - n + 1;
    for(long long i: v) {
        long long now = (n / i) * i;
        if(now != n) now += i;
        while(now <= m) {
//			cout << now << endl;
            if(!chk[now - n])  {
                chk[now - n] = 1;
                ans--;
            }
            now += i;
        }
    }
    cout << ans;
    cin >> n;

    return 0;
} 