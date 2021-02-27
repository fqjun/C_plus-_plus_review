#include <iostream>
#include <string>
using namespace std;

// 类模板对象做函数参数
// 三种传入的方式
// 1. 指定传入的类型  ：直接显示对象的数据类型
// 2. 参数模板化 ：将对象中的参数变为模板进行传递
// 3. 整个类模板化 ：将这个对象类型 模板化进行传递

template <class T1, class T2>
class Person {
 public:
  Person(T1 name, T2 age) {
    this->m_Age = age;
    this->m_Name = name;
  }

  void showPerson() {
    cout << "姓名:" << this->m_Name << " 年龄：" << this->m_Age << endl;
  }

  T1 m_Name;
  T2 m_Age;
};

// 1、指定传入类型 (最常用)
//参数和构造函数说明的参数列表一致即可

void printPerson1(Person<string, int>& p) { p.showPerson(); }

void test01() {
  Person<string, int> p("suanwukong", 100);
  printPerson1(p);
}

// 2、参数模板化
template <typename T1, typename T2>
void printPerson2(Person<T1, T2>& p) {
  p.showPerson();
  cout << "T1 的类型为：" << typeid(T1).name() << endl;  //查看类型
  cout << "T2 的类型为：" << typeid(T2).name() << endl;
}

void test02() {
  Person<string, int> p("zhubajie ", 90);
  printPerson2(p);
}

// 3、整个类模板化
template <class T>
void pringPerson3(T& p) {
  p.showPerson();
  cout<<"T的数据类型："<<typeid(T).name()<<endl;
}
void test03() {
  Person<string, int> p("tangseng", 30);
  pringPerson3(p);
}

int main() {
  // test01();
  test02();
    test03();

  system("pause");
  return 0;
}