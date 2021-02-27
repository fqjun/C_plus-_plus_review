#include <iostream>
#include <string>
using namespace std;

//类模板的基本语法
template <class NameType, class AgeType>
class Person {
 public:
  Person(NameType name, AgeType age) {
    this->m_Age = age;
    this->m_Name = name;
  }

  void showPerson() {
    cout << "Name:" << this->m_Name << "  Age:" << this->m_Age << endl;
  }

  NameType m_Name;
  AgeType m_Age;
};

void test01() {
  Person<string, int> p1("laoba", 20);
  p1.showPerson();
}

int main() {
  test01();
  system("pause");
  return 0;
}