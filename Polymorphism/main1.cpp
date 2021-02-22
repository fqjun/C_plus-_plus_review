#include <iostream>
#include <string>
using namespace std;

//分别用普通写法和多态技术实现计算器

//普通写法
class Calculator {
 public:
  int getResult(string oper) {
    if (oper == "+") {
      return m_Num1 + m_Num2;
    } else if (oper == "-") {
      return m_Num1 - m_Num2;
    } else if (oper == "*") {
      return m_Num1 * m_Num2;
    }

    //如果想拓展新的功能（除法），需要修改源代码
    //在真实开发中，提倡：开闭原则
    //开闭原则：对拓展进行开放，对修改进行关闭
  }

  int m_Num1;  //操作数1
  int m_Num2;  //操作数2
};

void test01() {
  //创建计算器对象
  Calculator C;
  C.m_Num1 = 10;
  C.m_Num2 = 10;

  cout << C.m_Num1 << "+" << C.m_Num2 << "=" << C.getResult("+") << endl;

  cout << C.m_Num1 << "-" << C.m_Num2 << "=" << C.getResult("-") << endl;

  cout << C.m_Num1 << "*" << C.m_Num2 << "=" << C.getResult("*") << endl;
}

//利用多态实现计算器
//多态的好处
// 1、组织结构清晰
// 2、可读性强
// 3、对于前期和后期拓展以及维护性高

//实现计算器的抽象类
class AbstrustCalculator {
 public:
  virtual int getResult() { return 0; }

  int m_Num1;
  int m_Num2;
};

//加法计算器类
class AddCalculator : public AbstrustCalculator {
 public:
  virtual int getResult() { return m_Num1 + m_Num2; }
};

//减法法计算器类
class SubCalculator : public AbstrustCalculator {
 public:
  virtual int getResult() { return m_Num1 - m_Num2; }
};

//乘法计算器类
class MulCalculator : public AbstrustCalculator {
 public:
  virtual int getResult() { return m_Num1 * m_Num2; }
};

void test02() {
  //多态使用条件
  //父类指针或者引用指向子类对象

  //加法运算
  AbstrustCalculator* abc = new AddCalculator;
  abc->m_Num1 = 100;
  abc->m_Num2 = 100;

  cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
  //用完后记得销毁
  delete abc;

  //减法运算
  abc = new SubCalculator;
  abc->m_Num1 = 100;
  abc->m_Num2 = 100;

  cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
  //用完后记得销毁
  delete abc;

  //乘法运算
  abc = new MulCalculator;
  abc->m_Num1 = 100;
  abc->m_Num2 = 100;

  cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
  //用完后记得销毁
  delete abc;
}

int main() {
  //   test01();
  test02();

  system("pause");
  return 0;
}