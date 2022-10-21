# Squashing Multiple Commits Into One

Basically combining multiple commits into one commit.

```
git rebase -i HEAD~<NUM>
```

- `<NUM>`: Go as far back as the parent of the oldest commit you want to squash

- Marking a commit with squash meld it with the commit previous to that.
- save and quit
- pops up an editor to ask you for a commit message for the newly compressed commit.
