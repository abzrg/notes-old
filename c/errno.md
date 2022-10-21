# ERRNO

- errno: Number of last error

- `#include <errno.h>`

- The `<errno.h>` header file defines the integer variable errno, which is set
  by system calls  and  some  library functions  in  the  event  of an error to
  indicate what went wrong.

- For some system calls and library functions (e.g., get‐ priority(2)), -1 is
  a valid return on success.  In such cases, a successful return can be
  distinguished from an error return by setting errno to zero before the  call,
  and  then,  if the call returns a status that indicates that an error may have
  occurred, checking to see if errno has a nonzero value.

- errno  is defined by the ISO C standard to be a modifiable `lvalue` of type
  int, and must not be explicitly declared;  errno  may be a macro.  `errno` is
  **thread-local**; setting it in one thread does not affect its  value  in any
  other thread.

- `%m`: (Glibc extension; supported by uClibc and musl.)  Print output of
  `strerror(errno)`. No argument is required.

