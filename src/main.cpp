#include <iostream>
#include <algorithm>
#include "random_nums.hpp"
#include "heap_sort.hpp"
#include "file_handler.h"

int main() {
  constexpr auto random_nums = create_array<int, 100>();

  std::for_each(begin(random_nums), end(random_nums), 
    [](auto num) {std::cout << num << " "; });
  std::endl(std::cout);

  sort::heap num_heap(random_nums);
  num_heap.sort_heap();
  num_heap.output();

  const std::string path = "string.txt";
  file_handler handler(path);
  const auto strings = handler.get_contents();
  sort::heap string_heap(strings);
  string_heap.sort_heap();
  handler.set_contents(string_heap.get_sequence());
  handler.write_file();
}
