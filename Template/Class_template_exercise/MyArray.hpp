// 自己的通用数组类
#pragma once
#include <iostream>
using namespace std;

template <class T>
class MyArray {
 public:
  //有参构造 参数 容量
  MyArray(int capacity) {
    cout << "you can gou zao " << endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new T[this->m_Capacity];
  }

  //拷贝构造 应对 MyArray(arr2);
  MyArray(const MyArray& arr) {
    cout << "kao bei gou zao " << endl;

    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    // this->pAddress = arr.pAddress;

    //深拷贝，重新开辟堆区内存并用指针维护
    this->pAddress = new T[arr.m_Capacity];

    //将 arr 中的数据都拷贝过来
    for (size_t i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];
    }
  }

  // operator = 防止浅拷贝问题 应对 arr1 = arr2 = arr3;
  MyArray& operator=(const MyArray& arr) {
    cout << "= operator" << endl;

    //先判断原来堆区是否有数据，如果有，先释放
    if (this->pAddress != NULL) {
      delete[] this->pAddress;
      this->pAddress = NULL;
      this->m_Capacity = 0;
      this->m_Size = 0;
    }

    //深拷贝
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[arr.m_Capacity];
    for (size_t i = 0; i < this->m_Size; i++) {
      this->pAddress[i] = arr.pAddress[i];
    }

    return *this;
  }

  //重载 [] 使arr[0]这样的操作可以对数组进行访问 可以实现 arr[0] = 100;
  T& operator[](int index) { return this->pAddress[index]; }

  //尾插法
  void Push_back(const T& val) {
    if (this->m_Capacity == this->m_Size) {
      return;
    }
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
  }
  //尾删法
  void Pop_back() {
    if (this->m_Size == 0) {
      return;
    }
    this->m_Size == ;
  }

  //析构函数
  ~MyArray() {
    cout << "xi gou han shu " << endl;
    if (this->pAddress != NULL) {
      delete[] this->pAddress;
      this->pAddress = NULL;
    }
  }

 private:
  T* pAddress;  //指针指向堆区开辟的真实数据

  int m_Capacity;  //数组容量

  int m_Size;  //数组大小
};