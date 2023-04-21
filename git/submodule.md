# Git `submodule`s


Git submodules allow you to keep a git repository as a subdirectory of
another git repository. Git submodules are simply a reference to another
repository at a particular snapshot in time. Git submodules enable a Git
repository to incorporate and track version history of external code.
-- [atlassian](https://www.atlassian.com/git/tutorials/git-submodule)


## adding a submodule

```sh
git add submodule <url> <path>
```

this will create a `.gitmodules` file in the super repo and git will
treat the submodule as a file in the super repo. However, inside the
submodule git treat it as a separate repo that has it's own history
and remotes and whatnot.

### add submodule to track a branch

```sh
git submodule add -b <branch> <url> <path>
# This will only add 'branch' entry in `.gitmodules` file under the
# submodule.

# update your submodule
git submodule update --remote
# It replaces the current checked out commit with the latest commit on
# the <branch> branch, THEN it populates the submodule with that commit
```


It's a little confusing to get used to this, but submodules are not on
a branch. They are, like you've said, just a pointer to a particular
commit of the submodule's repository.

This means, when someone else checks out your repository, or pulls your
code, and does `git submodule update`, the submodule is checked out to
that particular commit.

This is great for a submodule that does not change often, because then
everyone on the project can have the submodule at the same commit


If you want to move the submodule to a particular tag:

```sh
cd submodule_directory
git checkout v1.0
cd ..
git add submodule_directory
git commit -m "moved submodule to v1.0"
git push
```


Then, another developer who wants to have `submodule_directory` changed to
that tag, does this:

```sh
git pull
git submodule update --init
```

`git pull` changes which commit their submodule directory points to. `git
submodule update` actually merges in the new code.



references:
- [1](https://stackoverflow.com/a/15782629/13041067)
- [2](https://stackoverflow.com/a/18797720/13041067)
- [3](https://stackoverflow.com/a/1778247/13041067)


## modifying submodule

  ```sh
  cd submodule_repo
  git add; git commit -m 'add modifications'

  # first push changes in submodule
  git push <remote> <local_branch>:<remote_branch>

  # then commit the changes on submodule in the super repo
  git add submodule_repo
  git commit -m 'Update reference to the submodule_repo'

  # and finally push changes done on the super repo
  git push <remote> <local_branch>:<remote_branch>
  ```



## `init`

- [src](https://stackoverflow.com/a/46582526/13041067)

Imagine the repository has 10 `submodules` and you are interested in
only two `submodules` of these. In such a case, you may want to get
updates from only these two `submodules` from the remote repository from
time to time. `git submodule init -- <repo1> <repo2>` works well for this,
because once you execute the command `git submodule init -- <rep1> <rep2>`
for these two `submodules`, `git submodule update --remote` applies only
to them.


Let's say you clone a repository that has bunch of sub-modules. If you look at the
`.gitmodules` file:

```
[submodule "lib1"]
    path = lib1
    url = https://example.com/demo/lib1
[submodule "lib2"]
    path = lib2
    url = https://example.com/demo/lib2
[submodule "lib3"]
    path = lib3
    url = https://example.com/demo/lib3
[submodule "lib4"]
    path = lib4
    url = https://example.com/demo/lib4
```

all the modules are listed.

Let's say we don't need `lib3` and `lib4` for now and they are big
repositories, so we only want to add `lib1` and `lib2`. For that first
we "initialize" these two sub-modules

```sh
git submodule init -- lib1 lib2
```

Now let's see the contents of `.git/config`

```
...
[submodule "lib1"]
    active = true
    url = https://example.com/demo/lib1
[submodule "lib2"]
    active = true
    url = https://example.com/demo/lib2
```

This means something like "Ready to update `lib1` and `lib2` from
`example.com/demo`".


At this point, `lib1` and `lib2` directories are empty. You can clone
and checkout `lib1` and `lib2` with one command:

```sh
git submodule update
```


And finally, you can remove a submodule entry from `.git/config` using `deinit`

```sh
git submodule deinit <submodule>
```


## Update submodule (to mirror their remote)

Submodules are just references to certain commits. So when you want to
update libraries to new versions, you have to update the references. You
can do it by the below command.

```sh
git submodule update --remote
```


## Fix detached HEAD

- [src](https://stackoverflow.com/questions/44366417/what-is-the-point-of-git-submodule-init#comment92085769_46582526)

To fix the detached head state

```sh
git submodule foreach "git checkout master && git pull"
```


## Swap a git submodule with your own fork

- [src](https://www.atlassian.com/git/articles/core-concept-workflows-and-tips)

This is a very common workflow: you start using someone else's project
as submodule but then after a while you find the need to customize it
and tweak it yourself, so you want to fork the project and replace the
submodule with your own fork. How is that done?

Edit the `.gitmodules` file and change the url, and then run the following

```sh
git submodule sync
```

This updates `.git/config` which contains a copy of this submodule
list (you could also just edit the relevant [submodule] section of
`.git/config` manually).


## Remove a submodule

- [src](https://www.atlassian.com/git/articles/core-concept-workflows-and-tips)

It is a fairly common need but has a slightly convoluted procedure. To
remove a submodule you need to:


1. Delete the relevant line from the `.gitmodules` file.
1. Delete the relevant section from `.git/config.` (you can instead run `git submodule deinit <submodule>`)
1. Run `git rm --cached <path/to/submodule>` (no trailing slash).
1. Commit and delete the now untracked submodule files

## Pieces of advice

> Don't be too quick to dismiss `submodules` just because you heard
> they're bad. They are a poor solution if you want continuous
> integration, but they are a near-perfect solution if you want to
> embed code from an external project and you explicitly manage all
> pulls. This is often the best practice if you are integrating with
> a non-forked module that's not controlled by your organization. The
> problem is that they are a tempting solution in all kinds of other
> situations where they don't work very well at all. The best advice is
> to read up on how they work and evaluate your scenario.

---

As the Git Submodule Tutorial on
[kernel.org](https://archive.kernel.org/oldwiki/git.wiki.kernel.org/index.php/GitSubmoduleTutorial.html)
reminds us there are a few important things to note when interacting with your
remote repositories.

The __first__ is to always publish the submodule change before publishing the change
to the superproject that references it. This is critical as it may hamper others
from cloning the repository.

The __second__ is to always remember to commit all your changes before running `git
submodule update` as if there are changes they will be overwritten!


## Further Useful resources

- `man git-submodule`
- `man git-checkout`
- [Core concept workflows and tips (atlassian)](https://www.atlassian.com/git/articles/core-concept-workflows-and-tips)
