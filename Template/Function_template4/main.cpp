#include <iostream>
using namespace std;

// 普通函数与函数模板的区别：
// 1.普通函数调用时可以发生自动类型转换（隐式类型转换）
// 2.函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
// 3.如果利用显示指定类型的方式，可以发生隐式类型转换

int myAdd01(int a, int b) { return a + b; }

template <typename T>
T myAdd02(T a, T b) {
  return a + b;
}
void test01() {
  int a = 10;
  int b = 20;
  char c = 'c';

  cout << myAdd01(a, c) << endl;  // 普通函数能进行隐式类型转换
  // cout<<myAdd02(a,c)<<endl; //
  // 函数模板在使用自动类型推导的方式进行调用时，无法利用隐式类型转换
  cout
      << myAdd02<int>(a, c)
      << endl;  // 函数模板若想使用隐式类型转换，则需要使用显式指定类型的饭时进行调用
}

int main() {
  test01();
  // test02();
  system("pause");
  return 0;
}
l