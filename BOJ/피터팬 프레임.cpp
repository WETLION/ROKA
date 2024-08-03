#include <iostream>

// 3054번 피터팬 프레임

using namespace std;

string input, arr[2][2] = {{"..#.", ".#.#"}, {"..*.", ".*.*"}};

int main() {
  cin >> input;
  for(int j = 0; j < 5; j++) {
    if(j == 2) {
      for(int i = 0; i < input.length(); i++) {
        if(i % 3 == 2) {
          cout << "*." << input[i] << ".*";
          continue;
        }
        else if(!i || i % 3 != 0) {
          cout << "#";
        }
        cout << "." << input[i] << ".";
      }
      if(input.length() % 3) cout << "#";
    }
    else {
      for(int i = 0; i < input.length(); i++) {
        cout << arr[i % 3 == 2][j > 2 ? (4 - j) : j % 3];
      }
      cout << '.';
    }
    cout << endl;
  }

  return 0;
}