# Assertion in C

## When should I use assert?

- `assert` aborts the process, but is turned into a no-op when the program is
  compiled with `-DNDEBUG`, so it's a rather crude debugging tool and nothing
  more than that.

- You should only use `assert` to check for situations that **can't happen**,
  e.g., that violate the invariants or postconditions of an algorithm, but
  **probably not for input validation** (certainly not in libraries).

- When detecting invalid input from clients, be friendly and return an error
  code.

- An example use of `assert` could be: you've implemented an incredibly smart
  sorting algorithm and you want to check whether it really sorts. Since the
  sorting function is supposed to "just work" and therefore doesn't return
  a value, you can't add error returns without changing the API.

```c
#include <assert.h>

void sort(int *a, size_t n)
{
    recursive_super_duper_sort(a, 0, n);
    assert(is_sorted(a, n));
}

static bool is_sorted(int const *a, size_t n)
{
    for (size_t i=0; i<n-1; i++)
        if (a[i] > a[i+1])
            return false;

    return true;
}
```

- The conventional wisdom is to use assert() to help debug your code, to warn
  you when something "impossible", something that must not happen, has happened.
  This "warning" takes the form of _exiting your program_.

>  The  purpose  of  this macro is to help the programmer find bugs in his
>  program.   The  message  `assertion  failed  in  file  foo.c,  function
>  do_bar(), line 1287` is of no help at all to a user.


## Why not using assertion in Libraries

- Assertions will **not** work in _Release assemblies_, Exceptions is the only way
  to signal user of library that something is wrong

- Assertion is OK for **internal use in a private functions**. In the case
  client calls public method with incorrect parameters, exception should be
  thrown. Incorrect code must crash the program immediately, this is the best
  chance to fix the bug. It is a good idea to have different exception types for
  expected situations (_file not found_, _device not responding_ etc.) and
  caller bugs like incorrect parameter value. Client code should catch expected
  exceptions, leaving unexpected exceptions unhandled. When unexpected exception
  is thrown, client program crashes, and programmer just fixes the bug. However,
  if your library is written for internal use in the same company, it is OK to
  handle public method call errors like private, with assertions. But this
  approach must be strongly restricted and should **not** be used for
  **external** clients.
