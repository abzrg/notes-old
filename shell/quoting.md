# Quoting


## A quirk

```sh
FILES=`ls -1`

echo $FILES
# output:
# file1 file2 file3

echo "$FILES"
# output:
# file1
# file2
# file3
```
