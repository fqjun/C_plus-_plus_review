#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printVector(vector<int>& v) {
  for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void test01() {
  vector<int> v1;  //采用模实现类实现，默认构造函数
  for (size_t i = 0; i < 10; i++) {
    v1.push_back(i);
  }
  printVector(v1);

  vector<int> v2(v1.begin(),
                 v1.end());  //将 v1[begin(),end()]区间中的元素拷贝进 v2 本身
  printVector(v2);

  vector<int> v3(
      10, 100);  //创建并初始化 v3 容器，利用构造函数将 10 个 100 拷贝给 v3 本身
  printVector(v3);

  vector<int> v4(v3);  //拷贝构造函数，将 v3 拷贝进入 v4
  printVector(v4);

  vector<int> v5;
  v5.assign(10, 100);
  printVector(v5);

  v1.resize(13);
  printVector(v1);
}

int main() {
  test01();
  system("pause");
  return 0;
}