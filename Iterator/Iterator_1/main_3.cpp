#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector 容器互换

void printVector(vector<int>& v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

// 1、基本使用
void test01() {
  vector<int> v1;
  for (size_t i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);

  vector<int> v2;
  for (size_t i = 10; i > 0; i--) {
    v2.push_back(i);
  }
  printVector(v2);

  v1.swap(v2);
  printVector(v1);
  printVector(v2);
}

// 2、实际用途
//巧用 swap 可以收缩内存空间
void test02() {
  vector<int> v;
  for (size_t i = 0; i < 10000; i++) {
    v.push_back(i);
  }
  cout << "capacity of v:" << v.capacity() << endl;
  cout << "size of v:" << v.size() << endl;

  v.resize(3);  //重新指定大小
  cout << "capacity of v:" << v.capacity() << endl;
  cout << "size of v:" << v.size() << endl;

  //巧用 swap 收缩内存
  vector<int>(v).swap(v);

  cout << "capacity of v:" << v.capacity() << endl;
  cout << "size of v:" << v.size() << endl;
}

int main() {
  // test01();
  test02();

  system("pause");
  return 0;
}