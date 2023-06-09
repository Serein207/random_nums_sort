﻿#pragma once

namespace sort {
  template <typename Sequence>
  class heap {
    Sequence c;

  public:
    explicit heap(Sequence array): c(array) {
      adjust_heap(std::size(array));
    }

    void output(std::ostream& out = std::cout) {
      for (const auto& ele : c)
        out << ele << " ";
    }

    Sequence get_sequence() const { return c; }

    void sort_heap() {
      const std::size_t size = std::size(c);
      for (std::size_t i = 1; i < size; ++i) {
        std::swap(c[0], c[size - i]);
        heapify(size - i, 0);
      }
    }

  private:
    void heapify(const std::size_t len, std::size_t hole_index) {
      if (hole_index >= len) return;

      std::size_t child_index = hole_index * 2 + 1;
      std::size_t max_index = hole_index;

      if (child_index < len &&
        c[child_index] > c[max_index])
        max_index = child_index;

      if (child_index + 1 < len &&
        c[child_index + 1] > c[max_index])
        max_index = child_index + 1;

      if (max_index != hole_index) {
        std::swap(c[max_index], c[hole_index]);
        heapify(len, max_index);
      }
    }

    void adjust_heap(const std::size_t len) {
      const std::size_t parent = len / 2 - 1;
      for (int i = static_cast<int>(parent); i >= 0; --i) {
        heapify(len, i);
      }
    }
  };
}
