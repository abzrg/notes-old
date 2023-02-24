```
$(patsubst pattern,replacement,text)
```

finds words in `text` that match `pattern` and replaces them with `replacement`

example:

```make
deps := $(patsubst %.d,%.o,${obj})
-include ${deps}
```
