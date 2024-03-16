#include <iostream>
#include <string>

namespace study {
class test {
public:
  int number = -1;
  void ret() { std::cout << this->word << std::endl; }

  int num() { return a; }

  void reset_word() { this->word = "hello"; }

  int arr_size(int *arr) {
    if (cnt != -1)
      return cnt;
    for (cnt = 0;; cnt++) {
      if (arr[cnt] == -1)
        return cnt;
    }
  }

  void sort(int *arr) {
    int n = this->arr_size(arr);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (arr[i] > arr[j]) {
          int temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
        }
      }
    }
  }

  void arr_print(int *arr) {
    int n = this->arr_size(arr);
    for (int i = 0; i < n; i++) {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }

private:
  int a = 1, cnt = -1;
  std::string word = "return?";
};
} // namespace study

int main() {
  int arr[10] = {1, 2, 5, 1, 3, 7, 6, -1};
  std::cout << "Hello World!\n";
  study::test Test;
  Test.number = 1;
  std::cout << Test.number << std::endl;
  Test.arr_print(arr);
  Test.sort(arr);
  Test.arr_print(arr);
  Test.ret();
  Test.reset_word();
  Test.ret();
  std::cout << Test.num();
}