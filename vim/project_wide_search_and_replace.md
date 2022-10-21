# Project-Wide Search and Replace

Two Strategies:

  1. Run `:substitute` across all project files (OK for smaller projects)
  1. Run `:substitute` across project files that contain a match (for larger projects)


## Run `:substitute` across all project files

The first strategy is to populate the `arglist` with all of the files in the
project, then run the substitute command against them all:

  ```vim
  :args *.txt
  :argdo %s/Vimcasts\.\zscom/org/ge
  :argdo update
  ```

- This may mean that the `substitute` command runs in buffers that don’t contain
a match.


## Run `:substitute` across project files that contain a match (for larger projects)

The second strategy breaks the substitute command into two steps: find all
matches, then run the substitute command only in those buffers that contain a
match.

  ```vim
  :args *.txt
  :vimgrep /Vimcasts\.\zscom/g ##
  :cdo %s/Vimcasts\.\zscom/org/ge
  :cdo update
  ```

  - `\zs` sets start of match. In this case it searches for full phrase but only
  matches `com` that comes after it. Therefore the substitution only replaces
  `com` with `org`.

- `cdo` execute `{cmd}` in each valid entry in the `quickfix` list.
  - It works like doing this:

    ```vim
    :cfirst
    :{cmd}
    :cnext
    :{cmd}
    etc.
    ```
