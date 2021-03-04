#include <iostream>
using namespace std;
#define free_ptr(p) \
  if (p) delete p;  \
  p = NULL;
/* ---------------setting--------------- */
// 抽象策略类
class IWind {
 public:
  virtual ~IWind(){};
  virtual void blowWind() = 0;
};

// 具体策略角色
class ColdWind : public IWind {
 public:
  void blowWind() { cout << "Blowing cold wind!" << endl; };
};
//  具体策略角色
class WarmWind : public IWind {
 public:
  void blowWind() { cout << "Blowing warm wind!" << endl; }
};
//  具体策略角色
class NoWind : public IWind {
 public:
  void blowWind() { cout << "No Wind!" << endl; }
};
/* ---------------setting--------------- */

/* -------------realize-------------- */
// 环境类
class WindMode {
 public:
  WindMode(IWind* wind) : m_wind(wind){};
  ~WindMode() { free_ptr(m_wind); }
  void blowWind() { m_wind->blowWind(); };

 private:
  IWind* m_wind;
};
/* -------------realize-------------- */

int main(int argc, char* argv[]) {
  WindMode* warmWind = new WindMode(new WarmWind);
  WindMode* coldWind = new WindMode(new ColdWind);
  WindMode* noWind = new WindMode(new NoWind);

  warmWind->blowWind();
  coldWind->blowWind();
  noWind->blowWind();

  free_ptr(warmWind);
  free_ptr(coldWind);
  free_ptr(noWind);
  system("pause");
  return 0;
}