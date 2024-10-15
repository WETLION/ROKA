#include <iostream>
#include <cmath>

// 27918번 탁구 경기

using namespace std;

int n, d, p;
char input;

int main() {
    cin >> n;
    while(n--) {
        cin >> input;
        if(input == 'D') d++;
        else p++;
        if(abs(d - p) == 2) {
            break;
        }
    }
    cout << d << ':' << p;
    
    return 0;
}