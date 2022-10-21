# Vim's Runtime

- Source: summary of [this](https://thevaluable.dev/vim-runtime-guide-example/)
  article by [The Valueable Dev](https://thevaluable.dev/).


<!-- ----------------------------------------------- -->
## The order in which files are sourced

1. setting shell
1. user's configs
1. global configs
1. contents of after directory


<!-- ----------------------------------------------- -->
## Special (sub-)directories of the runtime path

1. `ftplugin`
1. `autoload`
1. `syntax`
1. `colors`
1. `ftdetect`
1. `compiler`


### `ftplugin`

- filetype plugin
- allow you to load pieces of configuration each time you open a buffer with a
  specific filetype.

  - Example: enable spelling each time you open a markdown file

  ```
  " file: $XDG_CONFIG_HOME/nvim/ftplugin/markdown.vim
  setlocal spell
  ```

- You need to keep in mind, however, that each time a buffer with the filetype
  markdown is created, the file `ftplugin/markdown.vim` will be sourced. As a
  result, you need to make sure that:

  - You reset any `autocommand` each time the file is sourced (using an
  `autocommand` group and `:au!`).
  - Every mapping you’re creating have the special argument `<buffer>`; for
  example,
    - `map <buffer> <leader>h echo "hello"`
  - You’re using `setlocal` instead of set to set options.
  - You’re using the `-buffer` argument for any __user command__.

- If you don’t respect these rules, your pieces of configuration won’t only be
  loaded for the buffers with a precise filetype, but for every buffer,
  globally.


### `autoload`

- This subdirectory lets you load your _custom functions_ when you call them,
  instead of loading them when Vim starts. As a result, it can significantly
  speed up Vim’s startup. These functions need to __begin with the path of the
  file they’re written in__, for Vim to know where to find them when you call
  them.

- For example, you can create a new file `autoload/general.vim` and use it to
  declare a new custom function `MyFunction`. This function needs to be called
  `general#MyFunction`, because it’s declared in the file `general.vim`. To call
  it, you can run `:call general#MyFunction`.

- You can also create subdirectories in the directory `autoload`. For example,
  you can create the file `autoload/path/to/general.vim`. In that case, you need
  to call your function `path#to#general#MyFunction`, describing the location of
  the file itself.

- I encourage you to put all your custom functions in the `autoload`
  subdirectory.


### `syntax`

### `colors`

### `ftdetect`

### `compiler`


<!-- ----------------------------------------------- -->
## The directory after



<!-- ----------------------------------------------- -->
## The runtime command

If you want to source manually some files from your runtime path, you can use
the command :runtime `<file>`. For example, if you want to load every files from
the colors subdirectory, you can run `:runtime colors/**/*.vim`.

- `:runtime!` (with a bang !) to source everything.


<!-- ----------------------------------------------- -->
## Disabling runtime files

- For debug purposes you can disable some of runtime files

  ```vim
  :source $VIMRUNTIME/ftoff.vim     " Disable the detection of filetypes
  :source $VIMRUNTIME/ftplugin.vim  " Enable ftplugin
  :source $VIMRUNTIME/ftplugof.vim  " Disable ftplugin
  :source $VIMRUNTIME/indent.vim    " Enable indentation
  :source $VIMRUNTIME/indoff.vim    " Disable indentation
  ```

<!-- ----------------------------------------------- -->
## Summary

Now that you know what Vim’s doing when it’s starting, you can add your pieces
of configuration in the good runtime subdirectory for more flexibility. You can
also try to speed up your startup if you find it too slow.


- Vim load specific configuration files and environment variables at startup
- You can use the options `-V` or `--startuptime` to get more details regarding
  Vim’s startup.
- The environment variable $VIM and `$VIMRUNTIME` are set during startup.
- The subdirectories in the runtime path have a meaning, sometimes affecting
  directly how they’re loaded at startup, and when.
- The runtime path subdirectory `after` is a special one: it’s a runtime path
  too (accepting the same subdirectories), and you can overwrite every other
  loaded config files in there.
- The command `:runtime` allows you to manually load config files from your
  runtime paths.
