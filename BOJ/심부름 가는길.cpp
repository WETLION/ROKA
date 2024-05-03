#include <iostream>

//5554번 심부름 가는길

using namespace std;

int main() {
    int sum = 0, input;
    for(int i = 0; i < 4; i++) {
        cin >> input;
        sum += input;
    }
    cout << sum / 60 << endl << sum % 60;
}