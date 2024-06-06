#include <iostream>
#include <string>

// 28702번 FizzBuzz

using namespace std;

string input;
int arr[3], start, diff;

void print(int n) {
  if(!(n % 15)) {
    cout << "FizzBuzz";
  }
  else if(!(n % 3)) {
    cout << "Fizz";
  }
  else if(!(n % 5)) {
    cout << "Buzz";
  }
  else {
    cout << n;
  }
}

int main() {
  for(int i = 0; i < 3; i++) {
    cin >> input;
    if(input == "FizzBuzz") {
      arr[i] = 15;
    }
    else if(input == "Fizz") {
      arr[i] = 3;
    }
    else if(input == "Buzz") {
      arr[i] = 5;
    }
    else {
      arr[i] = stoi(input);
      if(start) {
        diff = arr[i] - arr[start];
        if(i - start == 2) {
          diff /= 2;
        }
        print(arr[i] + diff * (3 - i));
        return 0;
      }
      start = i;
    }
  }
  for(int i = 1; ; i++) {
    int chk = 0;
    for(int j = 0; j < 3; j++) {
      if(start == j) continue;
      chk += !((arr[start] + i * (j - start)) % arr[j]);
    }
    if(chk == 2) {
      print(arr[start] + i * (3 - start));
      break;
    }
    // if(start == 0) {
    //   if(!((arr[start] + i) % arr[1]) && !((arr[start] + i * 2) % arr[2])) {
    //     print(arr[start] + i * 3);
    //     break;
    //   }
    // }
    // else if(start == 1) {
    //   if(!((arr[start] - i) % arr[0]) && !((arr[start] + i) % arr[2])) {
    //     print(arr[start] + i * 2);
    //     break;
    //   }
    // }
    // else {
    //   if(!((arr[start] - i * 2) % arr[0]) && !((arr[start] - i) % arr[1])) {
    //     print(arr[start] + i);
    //     break;
    //   }
    // }
  }

  return 0;
}