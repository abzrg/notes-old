To have only frame number instead of navigation (panel?)

```tex
\documentclass{beamer}

\setbeamertemplate{navigation symbols}{%
    \usebeamerfont{footline}%
    \usebeamercolor[fg]{footline}%
    \hspace{1em}%
    \insertframenumber/\inserttotalframenumber
}
\setbeamercolor{footline}{fg=black}
\setbeamerfont{footline}{series=\bfseries}

\begin{document}

\begin{frame}
    abc
\end{frame} 

\end{document}

```
