- `OutIt`: An output iterator `X` can only have a value `V` stored indirectly on
  it, after which it must be incremented before the next store, as in `(*X++)
  = V`, `(*X = V, ++X)`, or `(*X = V, X++)`.
- `InIt`: An input iterator `X` can represent a singular value that indicates
  end-of-sequence. If such an iterator does not compare equal to its
  end-of-sequence, you increment it, as in `++X`, `X++`, or (`V= *X++`). Once
  you increment any copy of an input iterator, none of the other copies can
  safely be compared, dereferenced, or incremented.
- `FwdIt`: A forward iterator `X` can take the place of an output iterator (for writing) or an input iterator (for reading). You
can, however read (via `V = *X`) what you just wrote (via `*X = V`) through a forward iterator. And you can make multiple copies of a forward
iterator, each of which can be dereferenced and incremented independently.
- `BidIt`: A bidirectional iterator `X` can take the place of a forward iterator. You can, however, also decrement a bidirectional iterator,
as in `--X`, `X--`, or (`V = *X--`).
- `RanIt`: A random-access iterator X can take the place of a bidirectional iterator. You can also perform much the same integer arithmetic on a random access iterator that you can on an object pointer. For `N`, an integer object, you can write `x[N]`, `x  N`, `x - N`, and `N + X`.
