#include <iostream>
#include <cmath>

// 1076번 저항

using namespace std;

string arr[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"}, input;
long long array[3];

int main() {
  for(int i = 0; i < 3; i++) {
    cin >> input;
    for(int j = 0; j < 10; j++) {
      if(arr[j] == input) {
        array[i] = j;
        break;
      }
    }
  }
  if(array[0] && !array[1]) cout << array[0] * (long long)pow(10, array[2] + 1);
  else if(!array[0]) cout << array[1] * (long long)pow(10, array[2]);
  else cout << array[0] << array[1] * (long long)pow(10, array[2]);

  return 0;
}