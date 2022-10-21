# LLDB

<!---------------------------------------------------------------------------->
## List source code

- `l` -- List relevant source code using one of several shorthand formats.
  - `l -` -- list previous ten lines
- `f` -- Select the current stack frame by index from within the current thread
  (see 'thread backtrace'.)

- You can also use the stop-line-count-after and stop-line-count-before settings
  to control how much source context is displayed at frame stops.

- Note that you can create your own regular expression command alias in your
  `~/.lldbinit` file with the same behavior as the top-of-tree lldb's l. See help
  command regex for the syntax and an example.

[Source](https://stackoverflow.com/a/17484386/13041067)


<!---------------------------------------------------------------------------->
## How to print an array

There are two ways to do this in lldb.

1. Most commonly, you use the `parray` lldb command which takes a `COUNT` and an
   `EXPRESSION`; `EXPRESSION` is evaluated and should result in a pointer to
   memory. lldb will then print `COUNT` items of that type at that address. e.g.

  ```
  (lldb) parray `count_variable` pointer_to_malloced_array

  parray 10 ptr
  where ptr is of type int *.
  ```

2. Alternatively, it can be done by casting the pointer to a pointer-to-array.
   For example, if you have a `int* ptr`, and you want to view it as an array of
   ten integers, you can do

  ```
  p *(int(*)[10])ptr
  ```

  Because it relies only on standard C features, this method works without any
  plugins or special settings. It likewise works with other debuggers like GDB
  or CDB, even though they also have specialized syntaxes for printing arrays.

3. To inspect variables you can use the `frame variable` command (`fr v` is the
   shortest unique prefix) which has a `-Z` flag which does exactly what you want:

   ```
   frame v array -Z10
   ```

- For those using the Xcode GUI who have a pointer only showing the first data
  elment, do the following: `right click on data pointer > View value as...
  > Custom Type...` In expression field put `*(double(*)[10])value_type`. That will
  print out the 10 values pointed to. You can modify double and 10 to be the
  type/quantity you want. 


[source (1&2)](https://stackoverflow.com/a/26303375/13041067)
[source (3)](https://stackoverflow.com/a/57495381/13041067)

<!---------------------------------------------------------------------------->
## Print multiple values with one command

```
(lldb) frame variable var1 var2 var3 var4
(lldb) fr v -o var1 var2 var3 var4
```

<!---------------------------------------------------------------------------->
## Define alias in `~/.lldbinit`

```
command alias mprint frame variable
```

to know how to define an alias: `help command alias`
