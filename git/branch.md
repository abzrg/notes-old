# git branches

Notes taken from the youtube video created by Tobias Gunther (freecodecamp)
https://www.youtube.com/watch?v=e2IbNHi4uCI


## Core Concepts


### The HEAD branch
<!-- {{{ -->

The currently "active" or "checked out" branch

> On branch master

<!-- }}} -->

### Local and Remote Branches
<!--{{{-->
99% of the time "working" with branches means your
local branches

```
# remote
origin/master
origin/feature

# local
master
feature
bugfix
```
<!--}}}-->

## 0. List branches
<!--{{{-->
```sh
git branch

git branch -a
```
<!--}}}-->

## 1. Creating new branches
<!--{{{-->
Based on your current HEAD branch

```sh
git checkout -b <new-branch-name>
# or
git switch -C <new-branch-name>
```

or based on a specific revision

```
git checkout -b <new-branch-name> <commit>
#or
git switch -C <new-branch-name> <commit>
```

IMPORTANT NOTE: You can only create new branches on local branches and unless you push them to remote repositories they remain on your computer only.
<!--}}}-->

## 2. Switching Branches
<!--{{{-->
using `checkout`/`switch` command

```sh
git checkout <other-branch>
# or
git switch <other-branch>
```
<!--}}}-->

## 3. Renaming branches
<!--{{{-->
- Renaming the current HEAD branch

```
git branch -m <new-name>
```

- Renaming any local branch

```
git branch -m <old-name> <new-name>
```

- "Renaming" a remote branch

```
# First, delete the current / old branch
git push origin --delete <old-name>

# Then, simply push the new local branch with the correct name:
git push -u origin <new-name>
```
<!--}}}-->

## 4. Publishing branches
<!--{{{-->
"Uploading" the local branch for the first time

```
git push -u origin <local-branch>
git push --set-upstream origin <local-branch>
```

- Note that `-u` or `--set-upstream` tells git to track remote branch.
(adds upstream (tracking) reference which is used by arg-less git-pull and other commands)
<!--}}}-->

## 5. Tracking branches
<!--{{{-->
Connecting branches with each other (With this connection (reference), we can do, for example, git push without mentioning the source/target branches)

local branch "develop" tracks... remote branch "origin/develop" and is ...

- 1 commit __ahead__ because c5 hasn't been pushed, yet.
- 2 commit __behind__ because c2+c4 haven't been integrated, yet.


```
c1 <--- c2 <------------------- c5 --- (local branch "develop") ----
         \
          \
           c3 <---- c4 ----- (remote branch "origin/develop") ----

```

We can establish a connection either by:
- publishing a local branch into a remote repository and track it
- "downloading" (tracking) a remote branch and bring it to the local repository


```sh
# publish a local branch into remote (git push) and track it (-u)
git push -u origin myLocalBranch


# track remote branches and bring them into local repository
# (--track or -t)
git branch --track <new-branch> origin/<base-branch>
# or
git checkout --track origin/<base-branch>
```

- Note that in the later, if you omit the name of the local branch it will use the name of the remote branch after 'origin/'.
- Also, in checkout command, it switch to the newly tracked branch.


- Note that we can change/unset the upstream tracking of a branch with

```sh
git branch -u <new-upstram>

git branch --unset-upstream # unset the upstream of the current branch
# You can explicitly give a name with -b in case.
```

To know if a branch is tracked you have several options:

```sh
# 1
git status -sb

# 2
git remote show origin

# 3
# git branch -vv [--contains]
```
<!--}}}-->

## 6. Pulling + pushing branches

Synchronizing your local + remote branches
<!--{{{-->
```
git pull
git push

git branch -v
```

TODO: What about `git fetch [--prune]`?
<!--}}}-->

## 7. Deleting branches
<!--{{{-->
1. Deleting a branch in your _local_ repository

  ```sh
  git branch -d <branch-name>
  ```

  - NOTE: you cannot the currently active (HEAD) branch. You have to switch to
    another branch first and then delete the branch

2. Deleting a branch in a _remote_ repository

  ```sh
  git push origin --delete <branch-name>
  ```

IMPORTANT NOTES:
 - When deleting a branch (local or remote), check if you should delete it's
   counter part (tracking) branch too. That way you make sure you aren't left
   with lots of obsolete branches and a messy git repository
 - Git may prevent you from deleting a branch that has commits that are not
   merged into or isn't on other branches. You can bypass that, with `-f`
   option, but exercise extra caution.
<!--}}}-->

## 8. Merging branches
<!--{{{-->
Integrating changes from other branch
into your current local HEAD branch.

```sh
# (1) checkout the branch that should receive the changes
git switch main

# (2) Execute the "merge" command with the name of the branch
#     that contains the desired changes
git merge feature/uploader
```

```
                    (merged commit)
                        \
c1 <---------- c3 <---- c4 <----- (main, HEAD) ---
 \                      /
  \                    /
   c2 <---------------/----- (feature/uploader) ---
```
<!--}}}-->

## 9. Rebasing branches
<!--{{{-->
An alternative way to integrate changes from another branch into your current
local HEAD branch

```
# (1) Check out the branch that should receive the changes
git switch feature/uploader

# (2) Execute the "rebase" commnad with the name of the branch that contains the
#     desired changes
git rebase main
```
<!--}}}-->

## 10. Comparing branches

Checking which commits are in branch-B, but not in branch-A

```
git log main..feature/uploader
```

This is especially useful when we want to integrate branch-B into branch-A and
want to know which commits gets integrated

One can also compare the local and remote branches

```
git log origin/main..main
```

This will show branches that are not pushed to upstream remote branch

- if you use three dots (`...`) instead of two you'll see all the differences in
  commits between branches, so not only commits that are in the second branch
  compared to the first but vice versa as well.

<!--
vim: foldmethod=marker
-->
