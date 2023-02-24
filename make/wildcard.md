# `wildcard` function



```make
SRC := $(wildcard *.c)
```

## Notes on `*` and `%`

- Both `*` and `%` are called wildcards in Make, but they mean entirely different
things.
  - `*` searches your filesystem for matching filenames. I suggest that you
  always wrap it in the wildcard function, because otherwise you may fall into a
  common pitfall described below.
    - `*` may be used in the target, prerequisites, or in the wildcard function.
    - Danger: `*` may not be directly used in a variable definitions
    - Danger: When `*` matches no files, it is left as it is (unless run in the
    wildcard function)



- `%` is really useful, but is somewhat confusing because of the variety of
situations it can be used in.
  - When used in "matching" mode, it matches one or more characters in a string.
  This match is called the stem.
  - When used in "replacing" mode, it takes the stem that was matched and
  replaces that in a string.
  - `%` is most often used in rule definitions and in some specific functions.
