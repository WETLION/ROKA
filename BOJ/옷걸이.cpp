#include <iostream>

// 27951번 옷걸이

using namespace std;

int n, arr[1000000], u, d, u_cnt, d_cnt, a_cnt;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] == 1) u_cnt++;
        else if(arr[i] == 2) d_cnt++;
        else a_cnt++; // 한 옷걸이에는 한 옷만 걸림
    }
    cin >> u >> d;
    if(u > u_cnt + a_cnt || d > d_cnt + a_cnt) { // 따라서 위 아래 옷걸이의 수를 통해 둘 다 걸리는 옷걸이에 뭘 걸어야 할지 정해줘야함
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 1 && u) {
            cout << "U";
            u--;
            u_cnt--;
        }
        else if(arr[i] == 2 && d) {
            cout << "D";
            d--;
            d_cnt--;
        }
        else {
            if(u > u_cnt) { // 이 과정을 통해 특정 옷걸이가 모자라는 것을 상쇄함
                cout << "U";
                u--;
            }
            else {
                cout << "D";
                d--;
            }
        }
    }
    cin >> n;

    return 0;
}