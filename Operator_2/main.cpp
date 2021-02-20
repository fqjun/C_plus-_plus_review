#include <iostream>
#include <string>
using namespace std;

class Person {
  friend ostream &operator<<(ostream &cout, Person &p);

 public:
  Person(int a, int b) {
    m_A = a;
    m_B = b;
  }
  //利用成员函数重载 左移运算符 <<，达不到目标的简化版本：cout << p;
  //因此不会利用成员函数重载左移运算符，无法实现 cout 在左侧
  /* void operator<<(Person &p){
  } */

 private:
  int m_A;
  int m_B;
};

//只能运用全局函数重载左移运算符
//本质 operator<< (cout,p) 简化为 cout<<p
ostream &operator<<(ostream &cout, Person &p) {
  cout << "m_A = " << p.m_A << "  m_B = " << p.m_B << endl;
  return cout;
}

void test01() {
  Person p(10, 10);

  cout << p << endl;
}

int main() {
  test01();

  system("pause");

  return 0;
}
