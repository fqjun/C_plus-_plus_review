#include <iostream>
using namespace std;
// #define free_ptr(p) \
//   if (p) delete p;  \
//   p = NULL;
// /* ---------------setting--------------- */
// // 抽象策略类
// class IWind {
//  public:
//   virtual ~IWind(){};
//   virtual void blowWind() = 0;
// };

// // 具体策略角色
// class ColdWind : public IWind {
//  public:
//   void blowWind() { cout << "Blowing cold wind!" << endl; };
// };
// //  具体策略角色
// class WarmWind : public IWind {
//  public:
//   void blowWind() { cout << "Blowing warm wind!" << endl; }
// };
// //  具体策略角色
// class NoWind : public IWind {
//  public:
//   void blowWind() { cout << "No Wind!" << endl; }
// };
// /* ---------------setting--------------- */

// /* -------------realize-------------- */
// // 环境类
// class WindMode {
//  public:
//   WindMode(IWind* wind) : m_wind(wind){};
//   ~WindMode() { free_ptr(m_wind); }
//   void blowWind() { m_wind->blowWind(); };

//  private:
//   IWind* m_wind;
// };
// /* -------------realize-------------- */

// void test() {
//   WindMode* warmwind_1 = new WindMode(new WarmWind());
//   cout << "---------------------" << endl;
//   int* ptr = new int(10);
// }

// int main(int argc, char* argv[]) {
//   WindMode* warmWind = new WindMode(new WarmWind());
//   WindMode* coldWind = new WindMode(new ColdWind());
//   WindMode* noWind = new WindMode(new NoWind());

//   warmWind->blowWind();
//   coldWind->blowWind();
//   noWind->blowWind();

//   free_ptr(warmWind);
//   free_ptr(coldWind);
//   free_ptr(noWind);
//   system("pause");
//   return 0;
// }

//电灯类
class Light {
 public:
  void on() { cout << "Light on !" << endl; }

  void off() { cout << "Light off !" << endl; }
};
//命令类
class Command {
 public:
  virtual void execute() {}
};
//具体命令类
class LigthOnCommand : public Command {
 public:
  LigthOnCommand(Light* lig) : light(lig) {}
  // execute方法
  void execute() { light->on(); }

 private:
  Light* light;
};

class LigthOffCommand : public Command {
 public:
  LigthOffCommand(Light* lig) : light(lig) {}
  void execute() { light->off(); }

 private:
  Light* light;
};

//遥控器类
class RemoteControl {
 public:
  void setCommand(Command* command) { slot = command; }
  void buttonOn() { slot->execute(); }

 private:
  Command* slot;
};
//客户代码
int main() {
  RemoteControl lightOnControl;
  RemoteControl lightOffControl;

  Command* onCommand = new LigthOnCommand(new Light());
  Command* offCommand = new LigthOffCommand(new Light());

  lightOnControl.setCommand(onCommand);
  lightOffControl.setCommand(offCommand);

  lightOnControl.buttonOn();
  lightOffControl.buttonOn();

  return 0;
}