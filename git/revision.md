
learn from reference: `git help revisions`

Use the following command as an example:

  ```sh
  git show --name-only HEAD
  # or
  git show --name-only  
  ```
    - `--name-only`: don't show the diff and stuff


1. `~`
  - most recent commit -> `HEAD`
  - commits before HEAD
    - `HEAD~`
    - `HEAD~~`, ...
    - `HEAD~N`

2. `^`

3. `:/regex`
  - search in commit messages
  - you may need to add `--` after it so that git can differentiate between the
    revision and the filename

  ```
  git show --name-only :ClassName --
  ```
