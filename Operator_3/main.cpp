#include <iostream>
#include <string>
using namespace std;

//重载递增预算符

//自定义整型
class MyInteger {
  friend ostream& operator<<(ostream& cout, MyInteger myint);

 public:
  MyInteger() { m_Num = 0; }

  //重载前置递增预算符  返回引用是为了让一个数据可以一直进行递增操作
  MyInteger& operator++() {
    m_Num++;       //先进行++运算
    return *this;  //再将自身作为返回值
  }
  //重载后置递增预算符 前置和后置是发生了函数重载
  //利用占位参数来对函数进行重载，区分前置和后置递增
  //这里不使用引用是因为 temp 为临时变量，如果引用返回临时变量则语法出错
  MyInteger operator++(int) {
    //先 记录结果
    MyInteger temp = *this;
    //后 递增
    m_Num++;
    //最后 将记录结果进行返回
    return temp;
  }

 private:
  int m_Num;
};

//重载<<运算符
ostream& operator<<(ostream& cout, MyInteger myint) {
  cout << myint.m_Num;
  return cout;
}

void test01() {
  MyInteger Myint;
  cout << ++(++Myint) << endl;
  cout << Myint << endl;
}

void test02() {
  MyInteger Myint;

  cout << (Myint++)++ << endl;
  cout << Myint << endl;
}

int main() {
  //   test01();
  test02();

  system("pause");

  return 0;
}
