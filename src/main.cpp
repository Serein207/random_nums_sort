#include <iostream>
#include <algorithm>
#include "random_nums.hpp"
#include "heap_sort.hpp"

int main() {
  constexpr auto random_nums = create_array<int, 10>();

  std::for_each(begin(random_nums), end(random_nums), 
    [](auto num) {std::cout << num << " "; });
  std::endl(std::cout);

  sort::heap heap(random_nums);
  heap.sort_heap();
  heap.output();
}
