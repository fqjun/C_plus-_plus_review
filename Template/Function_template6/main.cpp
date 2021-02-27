#include <iostream>
#include <string>
using namespace std;

// 模板的局限性
//模板并不是万能的，有些特定数据类型，需要用具体化的方式做特殊实现

class Person {
 public:
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }
  string m_Name;
  int m_Age;
};

// 对比两个数据是否相等函数
template <typename T>
bool myCompare(T &a, T &b) {
  if (a == b) {
    return true;
  } else {
    return false;
  }
}

void test01() {
  int a = 10;
  int b = 10;

  bool ret = myCompare(a, b);
  if (ret) {
    cout << "a = b" << endl;
  } else {
    cout << "a != b" << endl;
  }
}

// 利用具体化的 Person 的版本来实现代码，具体化会优先调用
template <>
bool myCompare(Person &a, Person &b) {
  if (a.m_Name == b.m_Name && a.m_Age == b.m_Age) {
    return true;
  } else {
    return false;
  }
}

void test02() {
  Person p1("laoyi", 10);
  Person p2("laoyi", 20);

  bool ret = myCompare(p1, p2);
  if (ret) {
    cout << "p1 = p2" << endl;
  } else {
    cout << "p1 != p2" << endl;
  }
}

int main() {
  // test01();
  test02();
  system("pause");
  return 0;
}
