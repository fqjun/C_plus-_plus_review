#include <iostream>
#include <string>

using namespace std;

//继承实现页面
//公共页面类
class BassPage {
 public:
  void header() {}
  void footer() {}
  void left() {}
};

// JAVA页面
class Java : public BassPage {
 public:
  void content() { cout << "Java学科视频" << endl; }
};
// Python页面
class Python : public BassPage {
 public:
  void content() { cout << "python学科视频" << endl; }
};
// C++页面
class Cpp : public BassPage {
 public:
  void content() { cout << "C++学科视频" << endl; }
};

//继承的好处：减少重复的代码
//语法：class 子类: 继承方式 基类
//继承方式
//公共继承、保护继承、私有继承

int main() { system("pause"); }