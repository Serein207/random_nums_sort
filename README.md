# random_nums_sort

:sparkles: NJUPT程序设计实践周项目，包含C++实现的编译期随机数生成，和运行期堆排序（因为编译期堆排不会写）

:relaxed: 本项目也提供一些可能有用的API ~~可能也没什么用~~ 

## 编译期随机数种子生成器 :pizza:

`random_generator.hpp`

```cpp
template <typename... RemainingString>
constexpr unsigned int create_seed(const char* first_str,
    const RemainingString&... remaining_strs);
 ```

## 编译期实数类型随机数生成器 :tulip:

`random_nums.hpp`

```cpp
template <typename T, std::size_t Size>
constexpr auto create_array(const T max)；
```

每次重新编译会生成一个 `max` 以内的随机数数组，所以好像真的没什么用 :expressionless:

## RAII文件处理器 :full_moon:

` file_handler.h`

```cpp
file_handler(std::string path);
~file_handler();
file_handler(const file_handler&) = delete;
file_handler(file_handler&&) = delete;

file_handler& operator=(const file_handler&) = delete;
file_handler& operator=(file_handler&&) = delete;

std::vector<std::string> get_contents();
void set_contents(std::vector<std::string> contents);
void write_file();
```

构造函数传入文件路径(`std::string`)

```cpp
file_handler(std::string path);
```

获取文件内容

```cpp
std::vector<std::string> get_contents();
```

设置将写入的文件内容

```cpp
void set_contents(std::vector<std::string> contents);
```

写入文件内容

```
void write_file();
```
