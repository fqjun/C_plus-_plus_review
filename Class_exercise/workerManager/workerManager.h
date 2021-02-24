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

  //统计文件中人数
  int get_EmpNum();

  //初始化员工
  void init_Emp();

  //显示职工
  void show_Emp();

  //按照职工编号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回 -1
  int IsExist(int id);

  //剔除职工
  void del_Emp();

  //修改职工
  void mod_Emp();

  //查找职工
  void find_Emp();

 private:
  // 记录文件中的人数个数
  int m_EmpNum;
  // Worker* 类型的员工指针数组的指针
  Worker** m_EmpArray;
  // 判断文件是否为空 标志
  bool m_FileIsEmp;
};