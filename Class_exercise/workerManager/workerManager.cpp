#include <workerManager.h>

workerManager::workerManager() {
  // 三种情况
  ifstream ifs;
  ifs.open(FILENAME, ios::in);  // 读文件

  // 1、文件不存在
  if (!ifs.is_open()) {
    cout << "文件不存在" << endl;
    // 初始化属性
    // 初始化人数
    this->m_EmpNum = 0;
    // 初始化数组指针
    this->m_EmpArray = NULL;
    //初始化文件是否为空
    this->m_FileIsEmp = true;
    ifs.close();
    return;
  }

  // 2、文件存在但数据为空
  char ch;
  ifs >> ch;  //右移读取文件的一位，利用 eof 判断是否为文件的最后一个标志
  if (ifs.eof()) {
    cout << "文件存在但数据为空" << endl;
    // 初始化属性
    // 初始化人数
    this->m_EmpNum = 0;
    // 初始化数组指针
    this->m_EmpArray = NULL;
    //初始化文件是否为空
    this->m_FileIsEmp = true;
    ifs.close();
    return;
  }

  // 3、文件存在，并且记录数据
  int num = this->get_EmpNum();
  cout << "职工人数为：" << num << endl;
  this->m_EmpNum = num;

  //开辟空间
  this->m_EmpArray = new Worker*[this->m_EmpNum];
  //将文件中的数据，存到数组中
  this->init_Emp();

  for (size_t i = 0; i < this->m_EmpNum; i++) {
    cout << "职工编号：" << this->m_EmpArray[i]->m_Id << " "
         << "姓名：" << this->m_EmpArray[i]->m_Name << " "
         << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
  }
}

void workerManager::menu() {
  cout << "******************************************" << endl;
  cout << "**********  欢迎使用职工管理系统!  **********" << endl;
  cout << "************** 0.退出管理程序 **************" << endl;
  cout << "************** 1.增加职工信息 **************" << endl;
  cout << "************** 2.显示职工信息 **************" << endl;
  cout << "************** 3.删除离职员工 **************" << endl;
  cout << "************** 4.修改职工信息 **************" << endl;
  cout << "************** 5.查找职工信息 **************" << endl;
  cout << "************** 6.按照编号排序 **************" << endl;
  cout << "************** 7.清空所有文档 **************" << endl;
  cout << "******************************************" << endl;
  cout << endl;

  cout << "请输入：";
}

void workerManager::exitSystem() {
  cout << "欢迎再次使用" << endl;
  system("pause");
  exit(0);
}

void workerManager::addEmp() {
  // 询问添加人数
  cout << "请输入添加人数:";
  int addNum = 0;  // 保存用户输入数量
  cin >> addNum;
  if (addNum > 0) {
    // 添加
    // 计算添加新空间的大小
    int newSize =
        this->m_EmpNum + addNum;  //新空间大小 = 原来记录人数 + 新增人数

    // 开辟新空间
    Worker** newSpace = new Worker*[newSize];

    // 将原来空间下的数据，拷贝到新空间下
    if (this->m_EmpArray != NULL) {
      for (size_t i = 0; i < this->m_EmpNum; i++) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    // 添加新数据 批量
    for (int i = 0; i < addNum; i++) {
      int id;       // 职工编号
      string name;  // 职工姓名
      int dSelect;  // 部门选择

      cout << "请输入第 " << i + 1 << " 个新职工的编号：" << endl;
      cin >> id;

      cout << "请输入第 " << i + 1 << " 个新职工的姓名：" << endl;
      cin >> name;

      cout << "请选择该职工的岗位：" << endl;
      cout << "1、普通员工" << endl;
      cout << "2、经理" << endl;
      cout << "3、总裁" << endl;
      cin >> dSelect;

      Worker* worker = NULL;

      switch (dSelect) {
        case 1:
          worker = new Employee(id, name, 1);  //多态
          break;
        case 2:
          worker = new Manager(id, name, 2);
          break;
        case 3:
          worker = new Boss(id, name, 3);
          break;

        default:
          break;
      }

      // 将创建的职工指针，保存到数组中
      newSpace[this->m_EmpNum + i] = worker;
      cout << "newspace :" << newSpace[0] << endl;
    }

    // 释放原有的空间
    delete[] this->m_EmpArray;

    // 更改新空间的指向
    this->m_EmpArray = newSpace;

    // 更新完后释放现有空间
    // delete[]
    // newSpace;//不能拥有这句，否则会导致newSpace内保存的空间被释放掉，导致指针丢失,要么放在最后

    // 更新新的职工人数
    this->m_EmpNum = newSize;

    // 成功添加后保存到文件中

    this->save();

    // 更新职工不为空标志
    this->m_FileIsEmp = false;

    // 提示添加成功
    cout << "成功添加 " << addNum << " 名新职工" << endl;

  } else {
    cout << "输入有误" << endl;
  }

  // 按任意键后 清屏回到上级目录
  system("pause");
  system("cls");
}

void workerManager::save() {
  ofstream ofs;
  ofs.open(FILENAME, ios::out | ios::app);

  for (size_t i = 0; i < this->m_EmpNum; i++) {
    ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name
        << " " << this->m_EmpArray[i]->m_DeptId << endl;
  }

  ofs.close();
}

int workerManager::get_EmpNum() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);  //打开文件，读

  int id;
  string name;
  int dId;

  int num = 0;

  while (ifs >> id && ifs >> name && ifs >> dId) {
    num++;
  }
  return num;
}

void workerManager::init_Emp() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int id;
  string name;
  int dId;

  int index = 0;

  while (ifs >> id && ifs >> name && ifs >> dId) {
    Worker* worker = NULL;

    if (dId == 1)  //普通职工
    {
      worker = new Employee(id, name, dId);
    } else if (dId == 2) {  //经理
      worker = new Manager(id, name, dId);
    } else {  //老板
      worker = new Boss(id, name, dId);
    }

    //找到相应的数据后，放入到数组中以完成初始化
    this->m_EmpArray[index] = worker;
    index++;
  }
  // 关闭文件
  ifs.close();
}

workerManager::~workerManager() {
  if (this->m_EmpArray != NULL) {
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
  }
}
