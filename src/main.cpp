#include <iostream>
#include "random_nums.hpp"

int main() {
  constexpr auto random_nums = create_array<int, 100>();
  for (const auto num :random_nums) {
    std::cout << num << " ";
  }

}
