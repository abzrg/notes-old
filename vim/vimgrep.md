# `:vimgrep`

vimgrep is Vim’s built-in command for searching across multiple files. It’s not
so fast as external tools like ack and git-grep, but it has its uses. vimgrep
uses Vim’s built-in regex engine, so you can reuse the patterns that work with
Vim’s standard search command.


- We can use the `:vimgrep` command to populate the `quickfix` list with search
  results from the current file:

  ```vim
  :vimgrep /{pattern}/ %
  " or
  :vim /{pattern}/ %
  ```

- Searching last pattern:

  ```vim
  :vimgrep /<C-r>// %
  ```

  - NOTE: On the command line, `<C-r>/` (that is: `CTRL-R` followed by `/`) will
  insert the last search pattern.


- Specifiying the set of files for vimgrep to search

  1. One or more filepaths (separated by whitespace)
  1. A wildcard
  1. A backtick expression
  1. The `##` symbol, representing the arglist


- Navigating `quickfix` list:

  | Ex command     | unimpaired map | effect                        |
  | -------------- | -------------- | ----------------------------- |
  | `:cprev[ious]` | `[q`           | reverse through quickfix list |
  | `:cnext`       | `]q`           | advance through quickfix list |
  | `:cfirst`      | `[Q`           | go to start of quickfix list  |
  | `:clast`       | `]Q`           | go to end of quickfix list    |


## Combining `vimgrep` with `git ls-files`

The `vimgrep` command uses Vim’s native regular expressions to search the
contents of multiple files. There are several ways that we can specify the list
of files to look inside, including `*` and `**` wildcards. It would be handy if
we could instruct vimgrep to look inside all of the files in the current
project, excluding those listed in the `.gitignore` file. That’s where the `git
ls-files` command comes in.

- `git help ls-files`: Show information about files in the index and the working
  tree


- If we wanted to search the contents of those files with `vimgrep`, we could
  wrap the git command in a _backtick expression_:
  ```vim
  :vimgrep /{pattern}/g `git ls-files`
  ```

- Alternatively, we could use the git ls-files command to populate the arglist.
  Then we could use the special symbol ## as the final argument for the vimgrep
  command:

  ```vim
  :args `git ls-files`
  :vimgrep /{pattern}/g ##
  ```

  - The `##` symbol is expanded to represent the filepath of each buffer in the
  arglist.


- Note that `git ls-files` omits untracked files. It only shows files in _index_
  and _working tree_.
  - You can view the list of untracked files by running `git ls-files --others`.


## Resources:

- [Search multiple files with `:vimgrep`](http://vimcasts.org/episodes/search-multiple-files-with-vimgrep/)
- [Vim-unimpaired plugin](https://github.com/tpope/vim-unimpaired)
- [Combining :vimgrep with git ls-files](http://vimcasts.org/blog/2013/03/combining-vimgrep-with-git-ls-files/)

