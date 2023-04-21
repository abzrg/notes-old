# `strace`

strace is a useful diagnostic, instructional, and debugging tool.
System administrators, diagnosticians and trouble-shooters will find it
invaluable for solving problems with programs for which the source is
not readily available since they do not need to be recompiled in order
to trace them


This tool shows the system calls[^1] of a process.

[^1]: In computing, a system call (commonly abbreviated to syscall) is the
    programmatic way in which a computer program requests a service from the
    operating system on which it is executed.


```sh
strace <program to be run>
strace -p <pid>
strace -p <pid> -e <syscall>  # <syscall>: read, write
```


## Resources

- [wikipedia](https://en.wikipedia.org/wiki/Strace)
