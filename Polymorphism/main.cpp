#include <iostream>
#include <string>
using namespace std;

//多态
//动物类
class Animal {
 public:
  virtual void speak() { cout << "动物在说话" << endl; }
};

class Cat : public Animal {
 public:
  void speak() { cout << "小猫在说话" << endl; }
};

class Dog : public Animal {
 public:
  void speak() { cout << "小狗在说话" << endl; }
};

//执行说话的函数
//地址早绑定 在编译阶段确定函数地址
//如果想执行猫说话，那么这个函数的地址不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
//只需要在父类的函数中加入关键字
// virtual，使函数成为虚函数，此时就会出现动态多态的现象

//动态多态满足条件：
// 1、有继承关系
// 2、子类（Dog::speak,Cat::speak）要重写父类（Animal::speak）的虚函数（virtual）
//补充：重写的定义：函数返回值类型、函数名、参数列表，这三者完全一致，称为重写

//动态多态使用
//父类的指针或者引用 指向子类对象
void doSpeak(Animal &animal)  // Animal & animal = cat;这里是引用指向了子类对象
                              // 父类引用指向子类对象，不需要强制类型转换
{
  animal.speak();  //函数地址不能提前确定
}

void test01() {
  Cat cat;
  doSpeak(cat);  //本意是让猫去说话，

  Dog dog;
  doSpeak(dog);
}

int main() {
  test01();
  system("pause");
  return 0;
}