```
DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CFLAGS =-DDEBUG
else
    CFLAGS =-DNDEBUG
endif
```
