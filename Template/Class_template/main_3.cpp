#include <iostream>
#include <string>
using namespace std;

// 类模板与继承

template <class T>
class Base {
  T m;
};

//错误，必须要知道父类中 T 的数据类型，才能继承给子类
// class son:public Base{
// 由于继承的原理，父类中的 T m
// 也被继承到子类中去，但是子类现在不是类模板，所以无法识别 T m
// 是什么数据类型的变量，无法计算子类所占的数据类型
class Son : public Base<int> {};

void test01() { Son s1; }

// 如果想灵活指定父类中T类型，子类也需要变成类模板
template <class T1, class T2>  // T1:int,T2:char
class Son2 : public Base<T2> {
 public:
  Son2() {
    cout << "T1的类型为:" << typeid(T1).name() << endl;
    cout << "T2 的类型为:" << typeid(T2).name() << endl;
  }
  T1 obj;
};

void test02() { Son2<int, char> S2; }

int main() {
  test01();
  test02();
  system("pause");
  return 0;
}