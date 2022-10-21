1. General latex
1. Math tips
1. Tools (make, git, emacs)
1. Best practice?
1. Templates


<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## BibTEx
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->

[](https://nhigham.com/2015/12/15/three-bibtex-tips/?relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=1&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=1&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=1&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=1)
[](https://nhigham.com/2021/11/04/top-bibtex-tips/?relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=0&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=0&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=0&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=0&relatedposts_hit=1&relatedposts_origin=2286&relatedposts_position=0)



<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## [Top tips for new latex users](https://nhigham.com/2015/09/29/top-tips-for-new-latex-users/)
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->

1. New Paragraphs
1. Math mode
1. Mathematical Functions in Roman
1. Maths Expressions
1. Text in Displayed Equations
1. Bibtex
1. Spelling Errors and $\LaTeX$ errors
1. Quotation mark



<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## [How to Space Displayed in Mathematical Equations](https://nhigham.com/2022/07/14/how-to-space-displayed-mathematical-equations/)
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->


- Better option: `\qty{value}{unit}`
  - use this instead of `\SI`
  - [more info](https://tex.stackexchange.com/a/20964/220469)

1. Equation with Qualifying Expression
2. Equation with conjunction
3. Multiple equations



<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## [Units of Measurement in $\LaTeX$](https://tex.stackexchange.com/a/325971/220469)
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->

- References:
  - [SI Unit rules and style conventions](https://physics.nist.gov/cuu/Units/checklist.html)


- Note that SI units are to be typeset in roman type, not italics!

- One of the best way to typeset (SI-)units is the `siunitx` package by
  __Joseph Wright__. It is very elaborate and lets you customize the behaviour
  of the display command `\SI{value}{unit}` – please read the documentation...
  there are way to many features in this awesome package to explain everything
  in full detail in one post.

- Your example would 'translate' to

    ```latex
    \SI{2.98}{\meter\kilogram\per\cubic\second\per\ampere}

    % The lowercase version (\si[<options>]{<unit>}) is for typesetting only a
    % unit, without a value.
    \si{\micro\mol\of{CO$_2$}\per\meter\squared\second\}}
    ```

    ```latex
    The siunitx package provides the of command that can be used in this way:

    \si{\micro\mol\of{CO$_2$}\per\meter\squared\second\}
    It will add the information as a subscript (or other formats specified by the qualifier-mode)

    Here is an example:

    \documentclass{article}
    \usepackage{siunitx}
    \begin{document}
     \si{\gram\of{CO$_2$}}
   \end{document}}
    ```

- Other options

    ![other options of siunitx package](https://camo.githubusercontent.com/5e68dee37d07e72503c9983db35d4640a76dcdea4cc56b68791159c73ea7da8f/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f49714a77412e706e67)





<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## [Typesetting mathematics according to ISO standard](https://nhigham.com/2016/01/28/typesetting-mathematics-according-to-the-iso-standard/)
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->


- [important link](https://iupac.org/wp-content/uploads/2016/01/ICTNS-On-the-use-of-italic-and-roman-fonts-for-symbols-in-scientific-text.pdf)

1. Units of measurements.
  - Better option: using `siunitx` package

1. __Variables and generic functions are written in italic__. This, of course,
   is standard practice.

1. __Mathematical constants whose values do not change are written in roman__.
   Thus $e$, $i$, and $\pi$ should be in _roman_ font. However, standard
   `\LaTeX` fonts do not have upright lower case Greek letters, so an italic
   `\pi` is unavoidable.

    ```latex
    \newcommand{\euler}{e}
    \mathrm{\euler}

    \newcommand{\ramuno}{i} % ramuno was how some Italian mathematicians of the
                            % 16th century called the quantity that squared gives
                            % –1; then Euler started using i
    \mathrm{\ramuno}

    \mathrm{\pi}
    ```

1. Mathematical functions with a fixed meaning, such as `exp` and `sin`, are
   written in _roman_. Of course, `\LaTeX` has such definitions built in for
   many standard functions, but it is a common error for inexperienced users to
   write, for example, `$sin(x)$` (giving $sing(x)$) instead of `$\sin(x)$`
   (giving $\sin(x)$). The best way to define macros for additional functions
   is via `\DeclareMathOperator`, assuming you are using the `amsmath` package:

    ```latex
    \DeclareMathOperator{\diag}{diag}
    ```

1. __Mathematical operators are written in roman__. This includes the `d` in
   derivatives and integrals.

    ```latex
    \mathrm{d}x
    \mathrm{d}y
    \mathrm{d}z
    mathrm{\ldots}
    ```

- Although the second and fourth of these rules are not widely followed, they
  are appealing in that they distinguish variable quantities from fixed ones.

- A capital delta may appear in both forms: as an operator, hence roman, as in
  the forward difference operator $\Delta(f) = f(x+h) - f(x)$; and combined
  with a letter to denote a variable, hence italic, as in `A + \mathnormal{\Delta}A`
  (where in $\LaTeX$ the latter delta is typed as $\mathnormal{\Delta}$).

- The ISO standard explicitly says that named polynomials, such as the
  Chebyshev polynomials, should be written in roman: `\mathrm{T}_n(x)` instead
  of `T_n(x)`.  This certainly follows the rules above, since such polynomials
  have a fixed meaning, but I have never seen the upright font being used for
  such polynomials in practice.


### Useful macros

    ```latex
    % The number `e'.
    \def\eu{\ensuremath{\mathrm{e}}}
    % The imaginary unit.
    \def\iu{\ensuremath{\mathrm{i}}}
    % The differential operator.
    \def\du{\ensuremath{\mathrm{d}}}`
    ```

- The `\ensuremath` is not essential, but it means that you can type `\eu`,
  etc., outside math mode -- for example, in the phrase `the limit of this
  sequence is \eu`.

- You may want to rewrite the `\def` commands using `\newcommand`, so that if
  the `\eu` command has already been defined an error will be issued:

    ```latex
    \newcommand{\eu}{\ensuremath{\mathrm{e}}}
    ```

- With these definitions the example at the start of this article is typed as

    ```latex
    \int_C\frac{\eu^z}{z}\,\du z = 2\pi\iu.
    ```

- Note that if you are using Beamer with the recommended sans serif fonts, then
  `mathrm` should be replaced by `\mathsf` in these definitions.



<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->
## Use of `\,` instead of `~` as a thin space
<!-- -------------------------------------------------------- -->
<!-- -------------------------------------------------------- -->

For the differential, a thin space `\,` is preferable to `~`
