#include <iostream>
#include <string>
using namespace std;

//赋值运算符重载

class Person {
 public:
  Person(int age) { m_Age = new int(age); }

  ~Person() {
    if (m_Age != NULL) {
      delete m_Age;
      m_Age = NULL;
    }
  }

  //成员函数
  Person &operator=(Person &p) {
    //应该先判断是否由属性在堆区，如果有，先释放干净，再深拷贝
    if (m_Age != NULL) {
      delete m_Age;
      m_Age = NULL;
    }
    m_Age = new int(*p.m_Age);
    //返回对象本身
    return *this;
  }

  int *m_Age;
};

void test01() {
  Person p1(18);

  Person p2(20);

  Person p3(30);

  cout << "p1.Age = " << *p1.m_Age << endl;
  cout << "p2.Age = " << *p2.m_Age << endl;

  p3 = p2 = p1;  //赋值操作

  cout << "p1.Age = " << *p1.m_Age << endl;
  cout << "p2.Age = " << *p2.m_Age << endl;
  cout << "p3.Age = " << *p3.m_Age << endl;
}

int main() {
  test01();
  //   test02();

  system("pause");

  return 0;
}
