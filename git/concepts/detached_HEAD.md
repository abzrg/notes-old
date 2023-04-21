According to the [git immersion](http://gitimmersion.com/)

> A "detached `HEAD`" message in git just means that `HEAD` (the part
> of git that tracks what your current working directory should match)
> is pointing directly to a commit rather than a branch. Any changes
> that are committed in this state are only remembered as long as you
> don’t switch to a different branch. As soon as you checkout a new
> branch or tag, the detached commits will be "lost" (because `HEAD` has
> moved). If you want to save commits done in a detached state, you need
> to create a branch to remember the commits.



If you are working in your repo and do git checkout <SHA> you will be in
a "detached `HEAD`". You are not on a branch (the commit is likely to be
on multiple branches). You are checked out to a specific instance in the
history.

A detached `HEAD` can also occur when you are rebasing. You are checked
out to a specific commit.

You would need to create a branch in order to commit/push changes
because you would be creating commits that would be "in limbo" with no
way to identify them other than the SHA. Git will remove the commit
during its garbage collection because of it not being on a branch.

Checkout the "Detached `Head`" Section on [this
page](http://git-scm.com/docs/git-checkout) for more in depth
information.


## `git checkout [--detach]`

```sh
-d
--detach
```

Rather than checking out a branch to work on it, check out a commit for
inspection and discardable experiments. This is the default behavior
of `git checkout <commit> when <commit>` is not a branch name. See the
"DETACHED `HEAD`" section below for details.
