# Floating point comparison

- Using `math.isclose()`
  - Added in Python3.5
  - in older versions you can do sth like this:

  ```python
  def isclose(a, b, rel_tol=1e-09, abs_tol=0.0):
      return abs(a-b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol)
  ```
  - `rel_tol` is a relative tolerance, it is multiplied by the greater of the
  magnitudes of the two arguments; as the values get larger, so does the
  allowed difference between them while still considering them equal.
   - `rtol = absolute(A-B)/min(A,B)`

  - `abs_tol` is an absolute tolerance that is applied as-is in all cases. If
  the difference is less than either of those tolerances, the values are
  considered equal.
    - `atol = absolute(a-b)`

  - note when `a` or `b` is a numpy array,
  [`numpy.isclose`](http://docs.scipy.org/doc/numpy-dev/reference/generated/numpy.isclose.html)
  works.

- Replace `==` with `math.isclose()`

  ```python
  >>> import math
  >>> # Don't do this:
  >>> 0.1 + 0.2 == 0.3
  False

  >>> # Do this instead:
  >>> math.isclose(0.1 + 0.2, 0.3)
  True
  ```

- `<=` and `>=` with `math.isclose()`

  ```python
  >>> import math
  >>> a, b, c = 0.1, 0.2, 0.3

  >>> # Don't do this:
  >>> a + b <= c
  False

  >>> # Do this instead:
  >>> math.isclose(a + b, c) or (a + b < c)
  True
  ```

- If you are using numpy:
  - `numpy.allclose()`
  - `numpy.isclose()`

  ```python
  >>> import numpy as np

  >>> # Use numpy.allclose() to check if two arrays are equal
  >>> # to each other within a tolerance.
  >>> np.allclose([1e10, 1e-7], [1.00001e10, 1e-8])
  False

  >>> np.allclose([1e10, 1e-8], [1.00001e10, 1e-9])
  True

  >>> # Use numpy.isclose() to check if the elements of two arrays
  >>> # are equal to each other within a tolerance
  >>> np.isclose([1e10, 1e-7], [1.00001e10, 1e-8])
  array([ True, False])

  >>> np.isclose([1e10, 1e-8], [1.00001e10, 1e-9])
  array([ True, True])
  ```

  - default absolute tolerance: `1e-08`
  - default relative tolerance: `1e-05`

## Resources

1. https://davidamos.dev/the-right-way-to-compare-floats-in-python/
1. https://stackoverflow.com/a/33024979/13041067
1. https://medium.com/@suri.kunal007/what-is-the-difference-between-absolute-and-relative-tolerance-and-when-to-use-one-over-the-other-c0c8f7dc20a4
