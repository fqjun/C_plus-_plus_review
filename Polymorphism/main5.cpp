#include <iostream>
#include <string>
using namespace std;

// 零件抽象类
// CPU
class CPU {
 public:
  //抽象计算函数
  virtual void calculate() = 0;
};
// 显卡
class Vediocard {
 public:
  //抽象显示函数
  virtual void display() = 0;
};
// 内存条
class Memory {
 public:
  //  抽象存储函数
  virtual void storage() = 0;
};

// 电脑类
class Computer {
 public:
  // 构造函数中传入三个零件的指针
  Computer(CPU* cpu, Vediocard* vc, Memory* mem) {
    this->m_cpu = cpu;
    this->m_vc = vc;
    this->m_mem = mem;
  }
  // 提供工作的函数
  void doWork() {
    // 调用每个零件工作的接口
    m_cpu->calculate();
    m_vc->display();
    m_mem->storage();
  }

  ~Computer() {
    if (m_mem != NULL) {
      delete m_mem;
      m_mem = NULL;
    }
    if (m_cpu != NULL) {
      delete m_cpu;
      m_cpu = NULL;
    }
    if (m_vc != NULL) {
      delete m_vc;
      m_vc = NULL;
    }
  }

 private:
  CPU* m_cpu;
  Vediocard* m_vc;
  Memory* m_mem;
};

// 具体厂商的零件
// Intel
class IntelCPU : public CPU {
 public:
  virtual void calculate() { cout << "Intel CPU" << endl; }
};
class IntelVC : public Vediocard {
 public:
  virtual void display() { cout << "Intel VedioCard" << endl; }
};
class IntelMEM : public Memory {
 public:
  virtual void storage() { cout << "Intel Memory" << endl; }
};

// Lenovo
class LenoveCPU : public CPU {
 public:
  virtual void calculate() { cout << "Lenove CPU" << endl; }
};
class LenoveVC : public Vediocard {
 public:
  virtual void display() { cout << "Lenove VedioCard" << endl; }
};
class LenoveMEM : public Memory {
 public:
  virtual void storage() { cout << "Lenove Memory" << endl; }
};

void test01() {
  CPU* intelcpu = new IntelCPU;
  Vediocard* intelvc = new IntelVC;
  Memory* Intelmem = new IntelMEM;

  cout << "第一台电脑开始工作" << endl;
  //创建第一台电脑
  Computer* computer_1 = new Computer(intelcpu, intelvc, Intelmem);
  computer_1->doWork();
  delete computer_1;

  cout << " --------------- " << endl;
  cout << "第二台电脑开始工作" << endl;
  //创建第二台电脑
  Computer* computer_2 =
      new Computer(new LenoveCPU, new LenoveVC, new LenoveMEM);
  computer_2->doWork();
  delete computer_2;
}

int main() {
  test01();
  //   test02();

  system("pause");
  return 0;
}