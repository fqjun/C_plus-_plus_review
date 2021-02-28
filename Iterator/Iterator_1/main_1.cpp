#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector 容器中存放自定义的数据类型

class Person {
 public:
  Person(string name, int age) {
    this->m_Name = name;
    this->m_Age = age;
  }

  string m_Name;
  int m_Age;
};

void test01() {
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 30);
  Person p4("ddd", 40);

  vector<Person> p;
  p.push_back(p1);
  p.push_back(p2);
  p.push_back(p3);
  p.push_back(p4);

  //遍历容器中的数据
  for (vector<Person>::iterator it = p.begin(); it != p.end(); it++) {
    //   (*it) 为 <>里面的内容,所以这里的 *it 为 Person
    cout << "Name is:" << (*it).m_Name << " Age is:" << (*it).m_Age << endl;
    cout << "Name is:" << it->m_Name << " Age is:" << it->m_Age << endl;
  }
}

// 存放自定义数据类型 指针
void test02() {
  Person p1("aaa", 10);
  Person p2("bbb", 20);
  Person p3("ccc", 30);
  Person p4("ddd", 40);

  vector<Person*> p;
  p.push_back(&p1);
  p.push_back(&p2);
  p.push_back(&p3);
  p.push_back(&p4);

  for (vector<Person*>::iterator it = p.begin(); it != p.end(); it++) {
    //   (*it) 为 <>里面的内容,所以这里的 *it 为 Person*
    cout << "Name is:" << (*it)->m_Name << " Age is" << (*it)->m_Age << endl;
  }
}

int main() {
  //   test01();
  test02();
  system("pause");
  return 0;
}
