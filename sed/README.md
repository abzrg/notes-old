# Sed -- Stream Editor


'sed' is a stream editor. A stream editor is used to perform basic text
transformations on an input stream (a file or input from a pipeline). While in
some ways similar to an editor which permits scripted edits (such as 'ed'),
'sed' works by making only one pass over the input(s), and is consequently more
efficient. But it is 'sed''s ability to filter text in a pipeline which
particularly distinguishes it from other types of editors.


- Normally sed is invoked like this:

  ```
  # Taking input file as commandline argument
  sed SCRIPT INPUTFILE...

  # Taking input file from the standard input
  sed SCRIPT < INPUTFILE...
  cat INPUTFILE | sed SCRIPT
  cat INPUTFILE | sed SCRIPT -  # Only GNU sed
  ```

- A sed script:

  ```
  sed <address><command><option>
  ```
  - Whitespace may be inserted before the first address and the command
  portions of the script.

  - Normally, sed cyclically copies a line of input, not including its
  terminating newline character, into a pattern space, (unless there is
  something left after a 'D' command), applies all of the commands with
  addresses that select that pattern space, copies the pattern space to the
  standard output, appending a newline, and deletes the pattern space.

  ```
  A line from file --> pattern space --> standard output
  ```

  - Some of the commands use a hold space to save all or part of the pattern
  space for subsequent retrieval.

- Command:
  - `p`: print the line (default)
  - `d`: delete the line
  - `s/foo/bar/`: substitute foo with bar in the line

- Address: could be _a line_, _range of lines_ or a _search pattern_

  ```sh
  sed '1d' nginx.conf  # Adress with a line
  sed '1,10d' nginx.conf  # Address with a range of lines
  sed '/on/d' nginx.conf  # Address with a pattern
  sed '1,10!d' nginx.conf  # Negate the address
  sed '/on/!d' nginx.conf  # All lines that don't have 'on' string/substring in them
  sed '\#on#d' nginx.conf  # Pattern surrounding (One can use a character other than / in this way)
  sed '\%/etc/nginx/proxy.conf%d' nginx.conf
  ```

- Execute multiple scripts: You can separate them with `;`

  ```sh
  sed '/on/d;/server/d' nginx.conf  # Remove every line with either 'on', or 'server' in it
  sed '11,14d;17,19d' nginx.conf  # All lines except 11-14 and 17-19
  ```

## Command line arguments

- `-i`: In-place edit (modifies the input file)
- `-i.bak` or `--in-place=.bak`: Edit files in place (makes backup if SUFFIX
supplied)
  - Only GNU sed
  - If the input file is a symlink, for changing the target of the symlink you
  should use the `--follow-symlinks` option. Otherwise it will create a new
  regular file with the name of the symlink file. The actual symlink is gone.

  ```sh
  sed -i.bak '11,14d;17,19d' nginx.conf
  ```

- `-e script, --expression=script`: Add the script to the commands to be executed

  ```sh
  sed -e '11,14d' -e '17,19d' nginx.conf
  ```

- `-f script-file, --file=script-file`: Add the contents of `script-file` to the
commands to be executed. The editing commands should each be listed on a
separate line. The commands are read from the standard input if script-file is
`-`.

  - File: script
  ```sed
  1d
  /on/d
  ```

  ```sh
  sed -f script nginx.conf
  ```

- `-E`:
  - By default it is the POSIX `Basic RE`.
  - You can change it with `-E` to `Extended RE`.

  ```sh
  sed -E '/^\s{2}/!d' nginx.conf
  ```

- `-n`: Suppress automatic printing of pattern space (`p` command)
  - Also `--quiet` or `--silent` in GNU sed.
  - `sed '/pattern/!d'` and `sed -n '/pattern/p'` are equivalent. So use `p`
  instead (with `-n`)

  ```sh
  sed -n '/on/p' nginx.conf  # Only print those lines that have 'on' in them
  ```

  ```sh
  sed -E '/^\s{2}/p' nginx.conf
  ```
