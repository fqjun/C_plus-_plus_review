#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

// deque 容器 赋值操作

// 只读状态，利用只读迭代器才能查看
void printDeque(const deque<int>& d) {
  for (deque<int>::const_iterator it = d.begin(); it < d.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void test01() {
  deque<int> d1;
  for (int i = 0; i < 10; i++) {
    d1.push_back(i);
  }
  printDeque(d1);

  deque<int> d2;
  d2 = d1;  //重载赋值
  printDeque(d2);

  deque<int> d3;
  d3.assign(d1.begin(), d1.end());  //区间赋值
  printDeque(d3);

  deque<int> d4;
  d4.assign(10, 100);  //重复赋值
  printDeque(d4);
}

int main() {
  test01();
  // test02();

  system("pause");
  return 0;
}