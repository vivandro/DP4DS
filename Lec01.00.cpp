
#include "Lec01.00.h"

#include <vector>
#include <iostream>

template <typename T>
void print_all(T beg, T end) {
  std::cout << "\n-------------------------\n";
  for(;beg != end; ++beg) {
    std::cout << *beg << " ";
  }
  std::cout << "\n-------------------------\n";
}

#define BEGEND_ARR(arr) (arr), ( (arr)+sizeof(arr)/sizeof((arr)[0]) )
#define BEGEND_STL(stl) (stl).begin(), (stl).end()

int main(int argc, char *argv[]) {

  int numArr[] = {99, 87, 65, 300, -98};
  std::vector<int> numVec(BEGEND_ARR(numArr));
  print_all(BEGEND_STL(numVec));
  VVDP4DS::sort_insertion(BEGEND_STL(numVec));
  print_all(BEGEND_STL(numVec));

  return 0;
}
