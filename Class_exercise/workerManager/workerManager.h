#pragma once
#include <boss/boss.h>
#include <config.h>
#include <employee/employee.h>
#include <manager/manager.h>
#include <worker/worker.h>

#include <fstream>

#define FILENAME "empFile.txt"

//管理类 负责如下内容
// 1、与用户的沟通菜单界面
// 2、对职工增删查改的操作
// 3、与文件的读写交互
class workerManager {
 public:
  // 构造函数
  workerManager();
  // 析构函数
  ~workerManager();

  // 显示菜单
  void menu();

  // 退出菜单
  void exitSystem();

  // 添加职工
  void addEmp();

  // 保存内容
  void save();

 private:
  // 记录文件中的人数个数
  int m_EmpNum;
  // 员工数组的指针
  Worker** m_EmpArray;
};