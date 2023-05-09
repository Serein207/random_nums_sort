#include <iostream>
#include <algorithm>
#include "random_nums.hpp"
#include "heap_sort.hpp"
#include "file_handler.h"
#include "sort_algorithms.hpp"

int main() {
  constexpr auto random_nums = create_array<int, 100>(100);
  
  std::for_each(begin(random_nums), end(random_nums),
                [](auto num) { std::cout << num << " "; });
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

  std::endl(std::cout);

  std::array<int, 5> array1 {5, 4, 3, 2, 1};
  sort::bubble_sort(array1);
  sort::print_array(array1);

  std::array<int, 5> array2 {5, 4, 3, 2, 1};
  sort::select_sort(array2);
  sort::print_array(array2);

  std::array<int, 5> array3 {5, 4, 3, 2, 1};
  sort::insert_sort(array3);
  sort::print_array(array3);

  std::array<int, 5> array4 {5, 4, 3, 2, 1};
  sort::merge_sort(array4);
  sort::print_array(array4);

  std::array<int, 10> array5 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  sort::quick_sort(array5);
  sort::print_array(array5);

  std::array<int, 10> array6 {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  sort::shell_sort(array6, 4);
  sort::print_array(array6);

  std::array<int, 10> array7 {109, 92, 83, 74, 65, 54 ,48, 30, 21, 1};
  sort::radix_sort(array2, 3);
  sort::print_array(array7);
}
