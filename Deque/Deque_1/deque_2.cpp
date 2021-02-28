#include <algorithm>
#include <deque>
#include <iostream>
#include <string>
using namespace std;

// deque 容器

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

  if (d1.empty()) {
    cout << "is empty" << endl;
  } else {
    cout << "size of d1 is" << d1.size() << endl;
  }

  d1.resize(15, 1);
  printDeque(d1);

  d1.resize(5);
  printDeque(d1);
}

int main() {
  test01();
  // test02();

  system("pause");
  return 0;
}