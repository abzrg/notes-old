# Register

- Nine Types of registers
  1. The unnamed (or default) register, `""`
  1. 10 numbered registers, `"0` to `"9`
  1. The small delete register, `"-`
  1. 26 name registers, `"a` to `"z` or `"A` to `"Z`
  1. Four read-only register, `":`, `".`, `"%` and `"#`
  1. The expression register, `"=`
  1. The selection and drop registers, `"*`, `"+` and `"~`
  1. The black hole register, `"_`
  1. Last search pattern register, `"/`


## Unnamed (or default) register `""`:

- Vim fills this register with text deleted with the `d`, `c`, `s`, `x`
commands or copied with the yank `y` command, regardless of whether or not
a specific register was used (e.g. `"xdd`).
- This is like the unnamed register is pointing to the last used register.
- An exception is the `_` register: `"_dd` does not store the deleted text in
any register

- Vim uses the contents of the unnamed register for any put command (`p` or
`P`) which does not specify a register.


## Numbered registers `"0` to `"9`

- Vim fills these registers with text from yank and delete commands.

- Numbered register `0` contains the text from the most recent __yank__ command,
unless the command specified another register with `"x`.

   Numbered register 1 contains the text deleted by the most recent delete or
change command, unless the command specified another register or the text is
less than one line (the small delete register is used then).  An exception is
made for the delete operator with these movement commands: |%|, |(|, |)|, |\`|,
|/|, |?|, |n|, |N|, |{| and |}|.  Register "1 is always used then (this is Vi
compatible).  The "- register is used as well if the delete is within a line.
Note that these characters may be mapped.  E.g. |%| is mapped by the matchit
plugin.
   With each successive deletion or change, Vim shifts the previous contents
of register 1 into register 2, 2 into 3, and so forth, losing the previous
contents of register 9.

## Small delete register `"-`

- This register contains text from commands that delete less than one line,
except when the command specifies a register with ["x].

## Named registers `"a` to `"z` or `"A` to `"Z`     *quote_alpha* *quotea*
Vim fills these registers only when you say so.  Specify them as lowercase
letters to replace their previous contents or as uppercase letters to append
to their previous contents.  When the '>' flag is present in 'cpoptions' then
a line break is inserted before the appended text.

## Read-only registers `":`, `".` and `"%`
These are '%', ':' and '.'.  You can use them only with the "p", "P",
and ":put" commands and with CTRL-R.
  ".  Contains the last inserted text (the same as what is inserted
  with the insert mode commands CTRL-A and CTRL-@).  Note: this
  doesn't work with CTRL-R on the command-line.  It works a bit
  differently, like inserting the text instead of putting it
  ('textwidth' and other options affect what is inserted).

  "%  Contains the name of the current file.

  ":  Contains the most recent executed command-line.  Example: Use
  "@:" to repeat the previous command-line command.
  The command-line is only stored in this register when at least
  one character of it was typed.  Thus it remains unchanged if
  the command was completely from a mapping.

## Alternate file register `"#`
Contains the name of the alternate file for the current window.  It will
change how the |CTRL-^| command works.
This register is writable, mainly to allow for restoring it after a plugin has
changed it.  It accepts buffer number: >

  ```vim
  let altbuf = bufnr(@#)
  ...
  let @# = altbuf
  ```

It will give error |E86| if you pass buffer number and this buffer does not
exist.
It can also accept a match with an existing buffer name: >
    let @# = 'buffer_name'
Error |E93| if there is more than one buffer matching the given name or |E94|
if none of buffers matches the given name.


## Expression register "=

This is not really a register that stores text, but is a way to use an
expression in commands which use a register.  The expression register is
read-write.

When typing the '=' after " or CTRL-R the cursor moves to the command-line,
where you can enter any expression (see |expression|).  All normal
command-line editing commands are available, including a special history for
expressions.  When you end the command-line by typing <CR>, Vim computes the
result of the expression.  If you end it with <Esc>, Vim abandons the
expression.  If you do not enter an expression, Vim uses the previous
expression (like with the "/" command).

The expression must evaluate to a String.  A Number is always automatically
converted to a String.  For the "p" and ":put" command, if the result is a
Float it's converted into a String.  If the result is a List each element is
turned into a String and used as a line.  A Dictionary or FuncRef results in
an error message (use string() to convert).

If the "= register is used for the "p" command, the String is split up at <NL>
characters.  If the String ends in a <NL>, it is regarded as a linewise
register.

## Selection registers `"*` and `"+`
Use these registers for storing and retrieving the selected text for the GUI.
See |quotestar| and |quoteplus|.  When the clipboard is not available or not
working, the unnamed register is used instead.  For Unix systems and Mac OS X,
see |primary-selection|.

## Black hole register `"_`
When writing to this register, nothing happens.  This can be used to delete
text without affecting the normal registers.  When reading from this register,
nothing is returned.

## Last search pattern register `"/`
Contains the most recent search-pattern.  This is used for "n" and 'hlsearch'.
It is writable with `:let`, you can change it to have 'hlsearch' highlight
other matches without actually searching.  You can't yank or delete into this
register.  The search direction is available in |v:searchforward|.
Note that the value is restored when returning from a function
|function-search-undo|.

              *@/*
You can write to a register with a `:let` command |:let-@|.  Example: >
  :let @/ = "the"

If you use a put command without specifying a register, Vim uses the register
that was last filled (this is also the contents of the unnamed register).  If
you are confused, use the `:dis` command to find out what Vim will put (this
command displays all named and numbered registers; the unnamed register is
labelled '"').



## Help pages

- `:h` [`linewise-register`](http://vimdoc.sourceforge.net/htmldoc/motion.html#linewise)
- `:h` [`quotequote`](http://vimdoc.sourceforge.net/htmldoc/change.html#quotequote)
- `:h` [`x`](http://vimdoc.sourceforge.net/htmldoc/change.html#x)
- `:h` [`dd`](http://vimdoc.sourceforge.net/htmldoc/change.html#dd)
- `:h` [`yy`](http://vimdoc.sourceforge.net/htmldoc/change.html#yy)
- `:h` [`p`](http://vimdoc.sourceforge.net/htmldoc/change.html#p)
