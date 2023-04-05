# sort


```cpp
#include <algorithm>
std::sort(startIt, endIt, [compFn])
std::stable_sort(startIt, endIt, [compFn])
```

## `std::sort`

This is an algorithm with linearithmic time complexity `O(nlogn)` that you can use to order the elements of container from `begin` to `end`.
The ordering by default is ascending for numeric values and lexicographical for string values.
Ordering of equivalent elements are not guaranteed to keep their same order.


```cpp
std::vector<int> v = { 3,2,4,1 };
std::sort(v.begin(), v.end()) // 1 2 3 4
```

sort part of data structure

```cpp
std::vector<int> v = { 3,2,4,1 };
std::sort(v.begin(), v.begin() + 2) // 2 3 4 1
```

sorting strings

```cpp
std::vector<std::string> v = { "mouse", "dog", "cat", "ant", "moth", "elephant" }
std::sort(v.begin(), v.end()) // ant cat dog elephant moth mouse
```

using custom comparison function

```cpp
std::vector<std::string> v = { "mouse", "dog", "cat", "ant", "moth", "elephant" }
auto sortByLength = [](const auto&, const auto& b) { return a.size() < b.size(); };
std::sort(v.begin(), v.end(), sortByLength) // ant cat dog moth mouse elephant
```


## `std::stable_sort`

Similar to `std::sort` except the ordering of equivalent elements are guaranteed to be kept the same.


## Neat Fact

Most implementation of `std::sort` are using a sort called [_introsort_](https://en.wikipedia.org/wiki/Introsort), which is a hybrid of quicksort + heap sort.
