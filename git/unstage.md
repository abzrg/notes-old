## Before the first commit

```
git rm --cached <file> <file>
git rm -r --cached .
```


## After the first commit

- The following will copy the last version of file from repo to index
```
# only for git version of > 2.23.0
git restore --staged file
```

- Copies file from index to working directory (discarding local changes)
  - It’s important to understand that `git restore <file>` is a dangerous command.
    Any local changes you made to that file are gone.
```
git restore <file>
git restore <file1> <file2> ...
git restore .
```

- The following will unstage any staged changes for the given file(s).
```
git reset -- <filePath>
```

- Note that `git rm --cached <filePath>` does not unstage a file, it actually
  stages the removal of the file(s) from the repo (assuming it was already
  committed before) but leaves the file in your working tree (leaving you with
  an untracked file).

- `git checkout -- <file>...` to discard changes in working directory
  - NOTE: It’s important to understand that `git checkout -- <file>` is
    a dangerous command. Any local changes you made to that file are gone


## References

- [stack overflow](https://stackoverflow.com/questions/6919121/why-there-are-two-ways-to-unstage-a-file-in-git)
- [git-scm](https://git-scm.com/book/en/v2/Git-Basics-Undoing-Things)
