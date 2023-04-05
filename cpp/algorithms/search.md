# search

```cpp
#include <algorithm>
std::binary_search(startIt, endIt, target [, compfn]) // O(log(n)) or O(n)
std::lower_bound(startIt, endIt, target, [, compfn]) // O(log(n)) or O(n)
std::upper_bound(startIt, endIt, target, [, compfn]) // O(log(n)) or O(n)
```


## `std::binary_search`

This is an algorithm with logarithmic time complexity `O(logn)` (for sequences that don't have random access iterator it is `O(n)`) that will return true if the value searched for exists in the sorted sequence (or at least partitioned with respect to the value searched for).

```cpp
std::vector<int> v = { 1, 3, 5, 7 };
std::binary_search(v.begin(), v.end(), 3); // true
std::binary_search(v.begin(), v.end(), 4); // false
```

using custom comparison function. Make sure to use the same comparison function that was used for sorting.

```cpp
std::vector<int> v = { 7, 5, 3, 1 };
#include <functional> // std::greater<T>
std::binary_search(v.begin(), v.end(), 3, std::greater<int>()); // true
```


## `std::lower_bound`

This is an algorithm with logarithmic time complexity `O(logn)` (for sequences that don't have random access iterator it is `O(n)`) that will return an iterator to  the first element __equal to__ or __greater than__ a given value in a sorted sequence.

One can think of this algorithm as `std::first_equal_to_or_greater_than`

```cpp
#include<iterator> // std::distance(firstIt, lastIt)
std::vector<int> v = { 1, 3, 3, 5, 7 };
auto it = lower_bound(v.begin(), v.end(), 3); // v.begin() + 1 (3)
auto it2 = lower_bound(v.begin(), v.end(), 4); // v.begin() + 3 (5)
auto it3 = lower_bound(v.begin(), v.end(), 8); // v.end() (not found)
std::distant(v.begin(), it); // 1
```

## `std::upper_bound`

This is an algorithm with logarithmic time complexity `O(logn)` (for sequences that don't have random access iterator it is `O(n)`) that will return an iterator to the first element __greater__ than a given value in a sorted sequence.

```cpp
std::vector<int> v = { 1, 3, 3, 5, 7 };
auto it = upper_bound(v.begin(), v.end(), 3); // v.begin() + 3 (5)
auto it2 = upper_bound(v.begin(), v.end(), 4); // v.begin() + 3 (5)
auto it3 = upper_bound(v.begin(), v.end(), 8); // v.end() (not found)
```

Both `lower_bound` and  `upper_bound` accept the fourth parameter as a comparison function.

```cpp
// last less than
template<typename ForwardIterator, typename T>
ForwardIterator last_less_than(ForwardIterator first, ForwardIterator last, T value)
{
  auto it = std::lower_bound(first, last, value);
  return (it == first ? last : --it);
}

std::vector<int> v = { 1, 3, 3, 5, 7 };
auto it = last_less_than(v.begin(), v.end(), 3); // v.begin() (1)
auto it2 = last_less_than(v.begin(), v.end(), 4); // v.begin() + 2 (3 (2nd one))
auto it3 = last_less_than(v.begin(), v.end(), 8); // v.begin() + 4 (7)
```
