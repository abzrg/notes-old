## Zsh bindings

src: https://jdhao.github.io/2019/06/13/zsh_bind_keys/

- Can not use HOME and END keys normally
  - You can use `showkey -a` to print the key codes.

  ```
  bindkey '^[[H' beginning-of-line
  bindkey '^[[F' end-of-line
  ```

- Bind key to run a custom command

  ```
  bindkey -s '^o' 'nvim $(fzf)^M'
  ```

  - `-s` option is used to translate the input string to output string so that
    when you press the shortcut, it is replaced with the command you want to run
  - `^M` or `\n` is used to represent the Enter key so that the command is run
    automatically.
