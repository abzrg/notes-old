To generate rules automatically so Makefile knows the dependency of each file
pass the following options to compiler

```
gcc ... -MMD -MF main.d
```

`main.d` contains the dependency information of main.c

```
$ cat main.d
main.o: main.c factorial.h
```

## Example 1:

```make
# ~~~

deps := $(patsubst %.d,%.o,${obj})
-include ${deps}
DEPFLAGS = -MMD -MF $(@:.o:.d)


# ~~~
```



## Example 2:

```
# ~~~

# The -MMD and -MP flags together generate Makefiles for us!
# These files will have .d instead of .o as the output.
CPPFLAGS := $(INC_FLAGS) -MMD -MP

# ~~~

# Include the .d makefiles. The - at the front suppresses the errors of missing
# Makefiles. Initially, all the .d files will be missing, and we don't want those
# errors to show up.
-include $(DEPS)

# END OF Makefile
```
