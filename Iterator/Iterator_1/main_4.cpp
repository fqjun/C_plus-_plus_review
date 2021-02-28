#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// vector容器 预留空间

void test01() {
  vector<int> v;

  //利用reserve预留孔家
  v.reserve(10000);
  int num = 0;  //统计开辟次数
  int* p = NULL;
  for (size_t i = 0; i < 10000; i++) {
    v.push_back(i);
    if (p != &v[0]) {
      p = &v[0];
      num++;
    }
  }
  cout << "num = " << num
       << endl;  //如果交给编译器自己操作的化就选哟搬家15次，否则就一次
}

int main() {
  test01();
  // test02();

  system("pause");
  return 0;
}