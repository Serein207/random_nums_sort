#include "random_generator.hpp"
#include <array>

template <typename T, std::size_t Size, size_t... Indices>
constexpr auto create_array_helper(std::index_sequence<Indices...>) {
  constexpr unsigned int seed = create_seed(__TIME__, __DATE__);
  std::array<T, Size> result{};
  ((result[Indices] = random<seed>::value), ...);
  return result;
}

template <typename T, std::size_t Size>
constexpr auto create_array() {
  return create_array_helper<T, Size>(std::make_index_sequence<Size>{});
}
