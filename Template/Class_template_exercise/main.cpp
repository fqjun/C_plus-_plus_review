#include <MyArray.hpp>
#include <iostream>
using namespace std;

void test() {
  MyArray<int> arr1(5);
  MyArray<int> arr2(arr1);

  MyArray<int> arr3(100);
  arr3 = arr1;
}

int main() {
  test();
  system("pause");
  return 0;
}