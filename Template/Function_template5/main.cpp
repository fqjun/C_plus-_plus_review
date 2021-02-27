#include <iostream>
using namespace std;

// 普通函数和函数模板的调用规则
// 1.如果函数模板和普通函数都可以实现，优先调用普通函数
// 2.可以通过空模板参数列表来强调调用函数模板
// 3.函数模板也可以发生重载
// 4.如果函数模板可以产生更好的匹配，优先调用函数模板
// 5.既然提供了函数模板，最好就不要提供普通函数，否则容易出现二义性

void myPrint(int a, int b) { cout << "调用的普通函数" << endl; }

template <typename T>
T myPrint(T a, T b) {
  cout << "调用函数模板" << endl;
}

template <typename T>
T myPrint(T a, T b, T c) {
  cout << "调用函数模板重载" << endl;
}

void test01() {
  int a = 10;
  int b = 20;
  int c = 30;

  // 1、如果函数模板和普通函数都能实现（同名函数），则编译器会优先调用普通函数
  // 注意：如果告诉编译器，普通函数是有的，但只是声明没有实现，或者不在当前文件内实现，就会报错找不到
  myPrint(a, b);  //调用普通函数

  // 2、可以通过空模板参数列表来强制调用函数模板
  myPrint<>(a, b);  //调用函数模板

  // 3、函数模板的重载
  myPrint(a, b, c);  //调用函数模板

  // 4、如果函数模板可以更好的匹配，则编译器会使用函数模板来进行调用
  char ch1 = 'a';
  char ch2 = 'b';
  myPrint(ch1, ch2);  //调用函数模板
}

int main() {
  test01();
  // test02();
  system("pause");
  return 0;
}
