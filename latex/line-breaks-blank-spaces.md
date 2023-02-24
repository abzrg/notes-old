# Line breaks and blank spaces


## Line breaks


- `\\`
- `\\*`:
  - breaks the line at the point of the command and additionally prohibits
  a page break after the forced line break.
- `\newline`
- `\hfill \break`


## Page breaks

- `\clearpage`
  - If the command `\clearpage` is used, and there are stacked floating elements,
  such as tables or figures, they will be flushed out before starting the new
  page. If the page break is inserted before all the figures are displayed,
  remaining images are inserted in an empty page before continuing with the text
  below the break point.
- `\newpage`


## Horizontal blank spaces

- `\hspace{1cm}`
  - Inserts a horizontal space whose length is 1cm. Other
  [LATEX units](https://www.overleaf.com/learn/latex/Lengths_in_LaTeX) can be
  used with this command.

- `\hfill`
  - Inserts a blank space that will stretch accordingly to fill the space
  available.[^1]

[^1]: The commands `\hrulefill` and `\dotfill` do the same as `\hfill` but instead of blank spaces they insert a horizontal ruler and a string of dots, respectively.

```tex
Horizontal \hspace{1cm} spaces can be inserted manually. Useful
to control the fine-tuning in the layout of pictures.

Left Side \hfill Right Side
```

## Vertical blank spaces

- `\vspace{5mm}`
  - Inserts a vertical spaces whose length is 5mm. Other LATEX units can be used
  with this command.

- `\vfill`
  - Inserts a blank space that will stretch accordingly to fill the vertical
  space available. That's why the line "Text at the bottom of the page." is
  moved to the bottom, and the rest of the space is filled in. There are other
  three commands commonly used to insert vertical blank spaces

- `\smallskip`
  - Adds a `3pt` space plus or minus `1pt` depending on other factors (document
  type, available space, etc)

- `\medskip`
  - Adds a `6pt` space plus or minus `2pt` depending on other factors (document
  type, available space, etc)

- `\bigskip`
  - Adds a `12pt` space plus or minus `4pt` depending on other factors (document
  type, available space, etc)


```tex
Text at the top of the page. Text at the top of the page.
Text at the top of the page. Text at the top of the page.
Text at the top of the page. Text at the top of the page.
Text at the top of the page.

\vspace{5mm} %5mm vertical space

This text still at the top, 5mm below the first paragraph.

\vfill

Text at the bottom of the page.
```


## Other commands

- `\break`
  - breaks the line without filling the current line. This will result in very
  bad formatting if you do not fill the line yourself. To fill the line, we can
  use it as given below.
  - `\hfill\break`
    - This will produce the same result as `\newline` and `\\`.

- Additionally, LATEX provides the following advanced option for line break.
  - `\linebreak[number]`
  - It breaks the line at the point of the command. The number provided as an
  argument represents the priority of the command in a range of 0 to 4. (0 means
  it will be easily ignored and 4 means do it anyway). When this line break
  option is used, LATEX will try to produce the best line breaks possible.


## References

- [Overleaf](https://www.overleaf.com/learn/latex/Line_breaks_and_blank_spaces)
