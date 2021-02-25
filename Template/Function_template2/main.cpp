#include <iostream>
using namespace std;

// 函数模板注意事项

template <
    class
    T>  // typename 可以替换成
        // class，函数一般用typename，类一般用class，这里的例子都是用的class
void mySwap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

// 1、自动类型推导，必须推导出一致的数据类型 T 才可以使用
void test01() {
  int a = 10;
  int b = 20;
  float c = 1.1;
  mySwap(a, b);  //正确!
  // mySwap(a,c);//错误！推导不出一致的 T 类型

  cout << "a = " << a << " b = " << b << endl;
}

// 2、模板必须要确定出 T 的数据类型，才可以使用
template <typename T>
void func() {
  cout << "func 的调用" << endl;
}

void test02() {
  // func();//错误,因为在没有推导的情况下，编译器无法得知使用什么数据类型，从而导致报错
  func<int>();
  //在告诉了编译器T的数据类型的时候，类似于实例化了之后，才能直接调用该函数
}

int main() {
  test01();
  system("pause");
  return 0;
}