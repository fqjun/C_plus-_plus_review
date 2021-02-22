#include <iostream>
#include <string>
using namespace std;

//纯虚函数和抽象类
class Base {
 public:
  //纯虚函数
  //只要有一个纯虚函数，这个类被称为抽象类
  //抽象类特点：
  // 1、无法实例化对象
  // 2、抽象类的子类，必须要重写父类中的纯虚函数，否则也属于抽象类
  virtual void func() = 0;
};

class Son : public Base {
 public:
  virtual void func() {}
};

void test01() {
  // Base b;//抽象类无法实例化对象
  // new Base;//抽象类无法实例化对象

  // Son s;

  Base* base = new Son;
  base->func();
  delete base;
}

int main() {
  //   test01();
  //   test02();

  system("pause");
  return 0;
}