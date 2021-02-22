#include <iostream>
#include <string>
using namespace std;

//虚析构和纯虚析构
class Animal {
 public:
  Animal() { cout << "Animal的构造函数调用" << endl; }
  //利用虚析构可以解决 父类指针释放子类对象时释放不干净的问题
  //   virtual ~Animal() { cout << "Animal的虚析构函数调用" << endl; }

  //纯虚析构,也需要代码实现
  //有了纯虚析构之后，这个类也属于抽象类，无法实例化对象
  virtual ~Animal() = 0;  //声明

  //纯虚函数
  virtual void speak() = 0;
};

Animal::~Animal() { cout << "Animal的纯虚析构函数调用" << endl; }

class Cat : public Animal {
 public:
  Cat(string name) {
    m_Name = new string(name);
    cout << "Cat的构造函数调用" << endl;
  }

  virtual void speak() { cout << *m_Name << "小猫在说话" << endl; }

  ~Cat() {
    if (m_Name != NULL) {
      cout << "Cat的析构函数调用" << endl;
      delete m_Name;
      m_Name = NULL;
    }
  }
  string* m_Name;
};

void test01() {
  Animal* animal = new Cat("Tom");
  animal->speak();
  //父类的指针在析构的时候不会调用子类的析构，导致子类如果有堆区的属性，则会出现内存泄漏的情况
  delete animal;
}

int main() {
  test01();
  //   test02();

  system("pause");
  return 0;
}