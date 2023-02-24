## Find the root of the project
src: https://vi.stackexchange.com/a/20606/30665

The following code snippet finds the root of the project where the .git folder
resides in. `fasdf`

```vim
let dir = finddir('.git/..', expand('%:p:h').';')
```
