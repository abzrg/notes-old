- There is two case:
  - fixing up non-root commit (like 6c6a213)
  - fixing up root commit (like 9ece26d)

  ```
  * 0f59402 <Linus Torvalds>  (HEAD -> master) Third commit
  * 6c6a213 <Linus Torvalds>  Second commit
  * 9ece26d <Linus Torvalds>  Initial commit
  ```

- fixing up non-root commits with hash of `<bad-commit-hash>`:

  ```sh
  git add ...
  git commit --fixup=<bad-commit-hash>
  git rebase --interactive --autosquash <hash>~
    # or
  git rebase --interactive --autosquash HEAD~<No>
    # No: parent of the bad commit
  ```

- fixing up root commit:

  ```sh
  git add ...
  git commit --fixup=<root-hash>
  git rebase --interactive --autosquash --root
  ```
