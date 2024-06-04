#include <iostream>
#include <string>

// 4949번 균형잡힌 세상

using namespace std;

int location;
string input;

bool balance(int type) {
  while(location < input.size()) {
    if(input[location] == '(') {
      location++;
      if(!balance(1)) return 0;
    }
    else if(input[location] == '[') {
      location++;
      if(!balance(-1)) return 0;
    }
    else if(input[location] == ')') {
      if(type != 1) return 0;
      return 1;
    }
    else if(input[location] == ']') {
      if(type != -1) return 0;
      return 1;
    }
    location++;
  }
  return type ? 0 : 1;
}

int main() {
  while(1) {
    getline(cin, input);
    // cout << input << endl;
    if(input == ".") break;
    location = 0;
    cout << (balance(0) ? "yes" : "no") << endl;
  }

  return 0;
}