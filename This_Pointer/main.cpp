#include <iostream>
using namespace std;

class Person {
 public:
  Person(int age) { this->age = age; }

  //若不是使用解引用&，则返回的是形式对象，而不是原始对象（类似于值传递与引用传递的区别）
  //所以我们使用引用的方式进行对象的返回，确保自己调用完还是自己在调用
  //因为我们的需求是：每次的返回值都是 p2 本身
  Person& PersonAddPerson(Person p) {
    this->age += p.age;
    cout << "this->age = " << this->age << endl;
    return *this;  //目的是为了返回对象，让对象能继续通过 .
                   //访问运算符来进行成员函数的调用，从而形成链式调用。
  }
  int age;
};

void test01() {
  Person p1(10);
  cout << "p1.age = " << p1.age << endl;

  Person p2(10);
  cout << "p2.age = " << p2.age << endl;
  p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
  cout << "p2.age = " << p2.age << endl;
}

int main() {
  test01();
  system("pause");
  return 0;
}