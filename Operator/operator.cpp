#include <iostream>
#include <string>
using namespace std;

class Person {
 public:
  Person() {}
  Person(int A, int B) {
    m_A = A;
    m_B = B;
    cout << "m_A:" << m_A << "  m_B: " << m_B << endl;
  }

  Person PersonAddPerson(Person &p) {
    Person temp;
    temp.m_A = this->m_A + p.m_A;
    temp.m_B = this->m_B + p.m_B;
    cout << "this->m_A:" << this->m_A << "  this->m_B:" << this->m_B << endl;
    return temp;
  }

  //通过成员函数重载了 + 号
  // Person operator+(Person &p) {
  //   Person temp;
  //   temp.m_A = this->m_A + p.m_A;
  //   temp.m_B = this->m_B + p.m_B;
  //   cout << "this->m_A:" << this->m_A << "  this->m_B:" << this->m_B << endl;
  //   return temp;
  // }

  //运算符重载同样发生函数重载
  // Person operator+(int Val) {
  //   Person temp;
  //   temp.m_A = this->m_A + Val;
  //   temp.m_B = this->m_B + Val;
  //   return temp;
  // }

  int m_A;
  int m_B;
};

//通过全局函数重载了 +  号
Person operator+(Person &p1, Person &p2) {
  Person temp;
  temp.m_A = p1.m_A + p2.m_A;
  temp.m_B = p1.m_B + p2.m_B;
  return temp;
}

//同理 运算符重载也可以类似于函数的重载
Person operator+(Person &p1, int Val) {
  Person temp;
  temp.m_A = p1.m_A + Val;
  temp.m_B = p1.m_B + Val;
  return temp;
}

void test01() {
  Person p1(10, 10);
  Person p2(10, 10);
  // p1.PersonAddPerson(p2);
  // Person p3 = p1.operator+(p2);
  // Person p3 = p1 + p2;
  Person p3 = p1 + 10;
  cout << "p1.m_A = " << p1.m_A << "  p1.m_b = " << p1.m_B << endl;
  cout << "p2.m_A = " << p2.m_A << "  p2.m_b = " << p2.m_B << endl;
  cout << "p3.m_A = " << p3.m_A << "  p3.m_b = " << p3.m_B << endl;
}

int main() {
  test01();

  system("pause");

  return 0;
}
