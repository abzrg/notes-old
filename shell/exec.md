# `exec` command

when we do `./script.sh` or `sh script.sh` the script is run inside a subshell
and _returns back_ afterwards to the same shell. If you want to override this
and _replace_ you current shell with the program you are going to run, use the
`exec` built-in command.
- the `-e` will run the command in a clean environment.


## References + further reading

- lpic1 by jadi
- https://www.baeldung.com/linux/exec-command-in-shell-script

