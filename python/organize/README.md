# Organize Python Code

## Use modules and packages

- module: a Python file
- package: a directory containing multiple Python modules + the `__init__.py` file

When one imports a package (only first time), the code inside the `__init__.py`
of that package  will execute once.

With this once can

- do initialization code inside of their package
- import thing from `__init__.py` without letting the user of the package know what is actually in the package (encapsulation?)

Use modules and packages to separate your code. if you have one large file
containing multiple classes, multiple functions etc. that doesn't make sense to
be in one place, separate it in multiple modules and packages and write the
appropriate `import` statement to bring everything into the file you need.


```
proj
├── main.py
└── physics
    ├── __init__.py
    ├── angular_momentum.py
    ├── forces.py
    └── gravity.py
```

<!---->

## One class = One file

- Put each of your classes in an individual file.
- Some people don't do this and there are exceptions.
- According to PEP8, choose `snake_case` for module names and `PascalCase` for
  class names.
- If you need to have another class in your module, just import it.

## Group related functionality together


```

proj
├── utils
├── src
├── tests
└── __init__py
```

## Separate helper functions and utilities


## Organize imports

- first 3rd party or builtin imports
- then after an empty line separation, import code from the current project
- alphabetically order them
