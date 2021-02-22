#include <iostream>
#include <string>
using namespace std;

//案例：制作饮品
//基类（抽象类)
class AbstrustDrinking {
 public:
  //四个步骤（方法）：煮水、冲泡、倒入杯中、加入辅料
  //煮水
  virtual void Boil() = 0;
  //冲泡
  virtual void Brew() = 0;
  //倒入杯中
  virtual void PourInCup() = 0;
  //加入辅料
  virtual void PutSomething() = 0;

  //规定流程
  void MakeDrink() {
    Boil();
    Brew();
    PourInCup();
    PutSomething();
  }
};
//子类
//茶
class Tea : public AbstrustDrinking {
 public:
  //煮水
  virtual void Boil() { cout << "农夫山泉煮水" << endl; }
  //冲泡
  virtual void Brew() { cout << "进行冲泡" << endl; }
  //倒入杯中
  virtual void PourInCup() { cout << "倒入杯中" << endl; }
  //加入辅料
  virtual void PutSomething() { cout << "加入枸杞" << endl; }
};
//咖啡
class Coffee : public AbstrustDrinking {
 public:
  //煮水
  virtual void Boil() { cout << "景田" << endl; }
  //冲泡
  virtual void Brew() { cout << "进行冲泡" << endl; }
  //倒入杯中
  virtual void PourInCup() { cout << "倒入杯中" << endl; }
  //加入辅料
  virtual void PutSomething() { cout << "加入牛奶和糖" << endl; }
};

void DoWork(AbstrustDrinking* drink) {
  drink->MakeDrink();
  delete drink;
}

void test01() {
  DoWork(new Tea);
  cout << "------------" << endl;
  DoWork(new Coffee);
}

int main() {
  test01();
  //   test02();

  system("pause");
  return 0;
}