# How to run shell function in xargs


It says command not found for the shell function defined somewhere above


[stackoverflow source](https://stackoverflow.com/a/11003457/13041067)


Exporting the function should do it (untested):

    ```sh
    export -f echo_var
    seq -f "n%04g" 1 100 | xargs -n 1 -P 10 -I {} bash -c 'echo_var "$@"' _ {}
    ```

You can use the builtin `printf` instead of the external `seq`:

    ```sh
    printf "n%04g\n" {1..100} | xargs -n 1 -P 10 -I {} bash -c 'echo_var "$@"' _ {}
    ```

Also, using `return 0` and `exit 0` like that masks any error value that might be produced by the command preceding it. Also, if there's no error, it's the default and thus somewhat redundant.

@phobic mentions that the Bash command _**could**_ be simplified to

    ```sh
    bash -c 'echo_var "{}"'
    ```

moving the `{}` directly inside it. **But** it's **vulnerable to command injection** as pointed out by @Sasha.

Here is an example why you **should not use** the embedded format:

    ```
    $ echo '$(date)' | xargs -I {} bash -c 'echo_var "{}"'
    Sun Aug 18 11:56:45 CDT 2019
    ```

Another example of **why not**:

    ```sh
    echo '\"; date\"' | xargs -I {} bash -c 'echo_var "{}"'
    ```

This is what is output **using the safe format**:

    ```
    $ echo '$(date)' | xargs -I {} bash -c 'echo_var "$@"' _ {}
    $(date)
    ```

This is comparable to using [parameterized][1] SQL [queries][2] to avoid [injection][3].


I'm using `date` in a command substitution or in escaped quotes here instead of the `rm` command used in Sasha's comment since it's non-destructive.


  [1]: https://blog.codinghorror.com/give-me-parameterized-sql-or-give-me-death/
  [2]: https://en.wikipedia.org/wiki/Prepared_statement
  [3]: https://rosettacode.org/wiki/Parametrized_SQL_statement
