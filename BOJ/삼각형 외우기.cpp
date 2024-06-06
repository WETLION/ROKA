#include <iostream>

// 10101번 삼각형 외우기

using namespace std;

int arr[3], sum, chk;

int main() {
  for(int i = 0; i < 3; i++) {
    cin >> arr[i];
    sum += arr[i];
    if(arr[i] != 60) chk = 1;
  }
  if(sum != 180) {
    cout << "Error";
  }
  else if(!chk){
    cout << "Equilateral";
  }
  else if(arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) {
    cout << "Isosceles";
  }
  else {
    cout << "Scalene";
  }

  return 0;
}