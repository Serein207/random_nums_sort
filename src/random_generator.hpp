#include <limits>
#include <utility>

constexpr std::size_t max_states = 101;

constexpr unsigned int create_seed(const char* str,
                                   const unsigned int initial_result = 0) {
  return *str == 0
           ? initial_result
           : create_seed(str + 1,
                         ((initial_result << 8ULL) + *str) & std::numeric_limits<unsigned int>::max());
}

template <typename... RemainingString>
constexpr unsigned int create_seed(const char* first_str,
                                   const RemainingString&... remaining_strs) {
  return create_seed(first_str, create_seed(remaining_strs...));
}

template <unsigned int Seed>
struct RandomBase {
  static constexpr unsigned int value =
    (134775813ULL * Seed + 1ULL) & std::numeric_limits<unsigned int>::max();
  using next = RandomBase<value>;
};

template <unsigned int Seed, std::size_t N>
struct RandomGenerator : RandomGenerator<Seed, N - 1>::next {
};

template <unsigned int Seed>
struct RandomGenerator<Seed, 0> : RandomBase<Seed> {
};

template <std::size_t N>
struct Flag {
  friend constexpr int adl_flag(Flag<N>);
};

template <typename T>
struct Writer {
  friend constexpr int adl_flag(T) { return 0; }
};

template <typename T, int = adl_flag(T { })>
constexpr std::size_t is_adl_flag_defined(int) { return 1; }

template <typename T>
constexpr std::size_t is_adl_flag_defined(...) { return 0; }

template <std::size_t Z, std::size_t... Sizes,
          std::size_t R = ((is_adl_flag_defined<Flag<Z + Sizes>>(0)) + ...)>
constexpr std::size_t count_defined_adl_flags(
  std::integer_sequence<std::size_t, Sizes...>) {
  return R;
}

template <unsigned int Seed, std::size_t MaxN = max_states - 1, std::size_t Z = 0,
          typename T = std::make_integer_sequence<std::size_t, MaxN>,
          std::size_t Counter = count_defined_adl_flags<Z>(T { }),
          std::size_t = sizeof(Writer<Flag<Counter>>)>
using random = RandomGenerator<Seed, Counter>;
