#pragma once
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

namespace sort {

template <typename T>
void print_array(T& array) {
  for (const auto& ele : array) {
    std::cout << ele << " ";
  }
  std::cout << std::endl;
}

template <typename T>
void bubble_sort(T& array) {
  const std::size_t size = std::size(array);
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = 0; j < size - i - 1; ++j) {
      if (array[j] > array[j + 1])
        std::swap(array[j], array[j + 1]);
    }
  }
}

template <typename T>
void select_sort(T& array) {
  const std::size_t size = std::size(array);
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = i; j < size; ++j) {
      if (array[i] > array[j])
        std::swap(array[i], array[j]);
    }
  }
}

template <typename T>
void insert_sort(T& array) {
  const std::size_t size = std::size(array);
  for (std::size_t i = 0; i < size; ++i) {
    for (std::size_t j = i; j > 0; --j) {
      if (array[j] < array[j - 1]) {
        std::swap(array[j], array[j - 1]);
      } else {
        break;
      }
    }
  }
}

template <typename T>
void merge_sort(T& array) {
  using value_type = typename T::value_type;

  const std::size_t size = std::size(array);
  if (size <= 1) return;

  const std::size_t half_size = size / 2;
  std::vector<value_type> left_array(begin(array), begin(array) + half_size);
  std::vector<value_type> right_array(begin(array) + half_size, end(array));

  merge_sort(left_array);
  merge_sort(right_array);
  merge_sort_helper(left_array, right_array, array);
}

template <typename T, typename U>
void merge_sort_helper(T& left, T& right, U& array) {
  const std::size_t left_size = std::size(left);
  const std::size_t right_size = std::size(right);
  std::size_t left_index = 0, right_index = 0;

  while (left_index < left_size && right_index < right_size) {
    if (left[left_index] < right[right_index]) {
      array[left_index + right_index] = left[left_index];
      ++left_index;
    }
    else {
      array[left_index + right_index] = right[right_index];
      ++right_index;
    }
  }

  for (std::size_t i = left_index; i < left_size; ++i)
    array[i + right_index] = left[i];
  for (std::size_t i = right_index; i < right_size; ++i) 
    array[left_index + i] = right[i];
}

template <typename T>
void quick_sort(T& array) {
  _quick_sort(array, 0, std::size(array) - 1);
}

template <typename T>
void _quick_sort(T& array, const int64_t left, const int64_t right) {
  if (left >= right) return;

  const int64_t pos = partition(array, left, right);
  _quick_sort(array, left, pos - 1);
  _quick_sort(array, pos + 1, right);
}

template <typename T>
int64_t partition(T& array, const int64_t left, const int64_t right) {
  int64_t pos = left;
  for (int64_t i = left; i < right; ++i) {
    if (array[i] < array[right]) {
      std::swap(array[pos], array[i]);
      ++pos;
    }
  }
  std::swap(array[pos], array[right]);
  return pos;
}

template <typename T>
void shell_sort(T& array, std::size_t step) {
  const std::size_t size = std::size(array);
  while (step < size / 3) step = step * 3 + 1;

  while (step > 0) { 
    for (std::size_t i = 0; i < size; ++i) {
      for (std::size_t j = i; j >= step; j -= step) {
        if (array[j] < array[j - step])
          std::swap(array[j], array[j - step]);
      }
    }
    step /= 3;
  }
}

template <typename T>
void radix_sort(T& array, const std::size_t digits) {
  using value_type = typename T::value_type;
  const std::size_t size = std::size(array);
  std::array<std::vector<value_type>, 10> buckets;

  for (std::size_t index = 0; index < digits; ++index) {
    buckets.fill(std::vector<value_type>{});
    for (std::size_t i = 0; i < size; ++i) {
      std::size_t ele = array[i] / 
        static_cast<uint64_t>(std::pow(10, index)) % 10;
      buckets[ele].push_back(array[i]);
    }
    std::size_t array_index = 0;
    for (const auto& bucket : buckets) 
      for (const auto& ele : bucket) 
        array[array_index++] = ele;
      }
    }

template <typename T>
void bucket_sort(T& array) {
  using value_type = typename T::value_type;
  const std::size_t size = std::size(array);
  auto minmax = std::minmax_element(array.begin(), array.end());
  
  const std::size_t distance = (minmax.second - minmax.first) / 3;
  if (distance == 0) return;

  std::array<std::vector<value_type>, 3> buckets;
  for (std::size_t i = 0; i < size; ++i) {
    if (*minmax.first <= array[i] && array[i] < *minmax.first + distance)
      buckets[0].push_back(array[i]);
    else if (*minmax.first + distance <= array[i] < *minmax.first + 2 * distance)
      buckets[1].push_back(array[i]);
    else
      buckets[3].push_back(array[i]);
  }

  std::size_t index = 0;
  for (auto& bucket : buckets) {
    std::sort(bucket.begin(), bucket.end());
    for (const auto& ele : bucket)
      array[index++] = ele;
  }
}

template <typename T>
void brick_sort(T& array) {
  const std::size_t size = std::size(array);
  bool is_sorted = false;

  while (!is_sorted) {
    is_sorted = true;
    for (std::size_t i = 0; i < size - 1; ++i) {
      if (i % 2 == 0 && array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        is_sorted = false;
      }
      else if (i % 2 == 1 && array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        is_sorted = false;
      }
    }
  }

}
       
}