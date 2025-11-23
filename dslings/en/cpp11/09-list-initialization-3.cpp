// mcpp-standard: https://github.com/Sunrisepeak/mcpp-standard
// license: Apache-2.0
// file: dslings/cpp11/09-list-initialization-3.cpp
//
// Exercise: cpp11 | 09 - list initialization | Precautions
//
// Tips: Fix compiler errors, understand precautions for list initialization
//
// Docs:
//   - https://en.cppreference.com/w/cpp/language/list_initialization.html
//   -
//   https://github.com/Sunrisepeak/mcpp-standard/blob/main/book/src/cpp11/09-list-initialization.md
//   - https://en.cppreference.com/w/cpp/utility/initializer_list.html
//
// Auto-Checker command:
//
//   d2x checker list-initialization
//

#include <d2x/common.hpp>

#include <initializer_list>
#include <iostream>
#include <vector>

class MyVector {
  int mSize;
  int *data;

public:
  MyVector(int val) {
    mSize = 1;
    data = new int[mSize];
    data[0] = val;
  }

  MyVector(int v1, int sz) {
    mSize = sz;
    data = new int[mSize];
    for (int i = 0; i < sz; ++i) {
      data[i] = v1;
    }
  }

  MyVector(std::initializer_list<int> list) {
    mSize = list.size();
    if (mSize < 2) {
      data = new int[mSize];
      int i = 0;
      for (const auto &val : list) {
        data[i++] = val;
      }
    } else {
      // TODO: 将list的第二个元素作为新数组的size，第一个元素作为新数组中每个元素的值
    auto it = list.begin();
    int first = *it++;
    int newSize = *it;
    mSize = newSize;
    data = new int[mSize];
    for (int i = 0; i < mSize; ++i) {
        data[i] = first;
    }

    //   mSize = list[mSize - 1];
    //   data = new int[mSize];
    //   int i = 0;
    //   for (const auto &val : list) {
    //     data[i++] = list[0];
    //   }
    }
  }

  MyVector(const MyVector &other) = delete;
  MyVector(MyVector &&other) = delete;

  ~MyVector() { delete[] data; }

  int size() const { return mSize; }
};

struct Point {
  int x, y;

  Point(std::initializer_list<int> initList) : x{0}, y{0} {}
};

int main() {

  Point p1 = {1, 2};
  Point p2{3, 4};

  MyVector vec1(1);
  d2x_assert_eq(vec1.size(), 1);
  MyVector vec2{1};
  d2x_assert_eq(vec2.size(), 1);

  MyVector vec3(1, 10);
  d2x_assert_eq(vec3.size(), 10);
  MyVector vec4{1, 10};
  d2x_assert_eq(vec4.size(), 10);

//   D2X_WAIT

  return 0;
}