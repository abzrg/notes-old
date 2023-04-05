# reverse and rotate (+ \_copy)

```cpp
#include <algorithm>
template <typename BidIt>
void std::reverse( BidIt first, BidIt last ); // O(n)

template< class BidIt, class OutIt >
OutIt reverse_copy( BidIt first, BidIt last, OutIt result );

template< class FwdIt >
void rotate( FwdIt first, FwdIt n_first, FwdIt last ); // O()

template< class FwdIt, class OutIt >
OutputIt rotate_copy( FwdIt first, FwdIt n_first, FwdIt last, OutIt result );
```


## `std::reverse`

- complexity: `O(n)`
- will reverse the elements between the first and last iterators.

## `std::reverse_copy`

- complexity: `O(n)`
- will copy the reversed elements between first and last to the result iterator.


