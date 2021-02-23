#include <boss.h>
#include <config.h>
#include <employee.h>
#include <manager.h>
#include <worker.h>
#include <workerManager.h>

// 测试代码
void test01() {
  Worker* wk = NULL;
  wk = new Employee(1, "张三", 3);
  wk->show_Info();
  delete wk;

  wk = new Manager(2, "李四", 2);
  wk->show_Info();
  delete wk;

  wk = new Boss(3, "王五", 1);
  wk->show_Info();
  delete wk;
}

int main() {
  //实例化管理者对象
  workerManager* worker = new workerManager;
  int command = 0;
  do {
    //显示菜单
    worker->menu();

    cin >> command;

    switch (command) {
      case 0:  //退出系统
        worker->exitSystem();
        break;
      case 1:  //增加职工
        worker->addEmp();
        break;
      case 2:  //显示职工
        break;
      case 3:  //删除员工
        break;
      case 4:  //修改信息
        break;
      case 5:  //查找职工
        break;
      case 6:  //编号排序
        break;
      case 7:  //清空文档
        break;
      default:
        system("cls");
        break;
    }

  } while (command != 0);

  delete worker;

  system("pause");
}
