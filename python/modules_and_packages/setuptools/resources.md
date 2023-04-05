## Resources

src: chatgpt

In a `setuptools`-based Python project, `resources` refers to any non-Python files
that are required by the project, such as data files, configuration files, or
static assets like images or style-sheets. These resources need to be included in
the project distribution package so that they can be used by the project code or
by users who install the package.

`setuptools` provides a convenient way to include resources in a package
distribution using the `package_data` and `include_package_data` options in the
`setup`() function.

The `package_data` option allows you to specify a dictionary that maps package
names to lists of file patterns that should be included in the distribution
package. For example, if you have a package called `my_package` and you want to
include all files with the extension `.txt` in a subdirectory called data, you can
use the following code:

```python
setup(
    name='my_package',
    version='1.0',
    packages=['my_package'],
    package_data={'my_package': ['data/*.txt']},
)
```

The `include_package_data` option allows you to include all data files that are
found in your package directory, without having to specify them manually. You
can set this option to True in your `setup()` function, like this:

```python
setup(
    name='my_package',
    version='1.0',
    packages=['my_package'],
    include_package_data=True,
)
```

When you build a distribution package using `setuptools`, any resources specified
in `package_data` or included using `include_package_data` will be included in the
package distribution, along with the Python source code.


The location where resources are installed depends on how your package is
installed. When you install a package using `pip`, it will extract the contents of
the package distribution archive into the appropriate location on your system.

By default, resources included using setuptools's `package_data` or
`include_package_data` options will be installed in a subdirectory of the package
installation directory. The exact location of this directory depends on the
installation scheme used by pip.

For example, if you install a package called `my_package` that includes a data
file `data/my_data.txt` using `pip`, the data file will be installed in a directory
like this:

```
<sys.prefix>/lib/pythonX.Y/site-packages/my_package/data/my_data.txt
```

Here, `<sys.prefix>` is the root directory of your Python installation, and `X.Y` is
the version of Python you are using.

Note that you can also use `setuptools` to specify custom installation paths for
resources, using the `data_files` option. This option allows you to specify a list
of `(directory, files)` tuples that specify where to install data files relative
to the root of the file system. However, this option is less commonly used, as it
requires you to explicitly specify installation paths for each file, rather than
relying on `setuptools` to install resources in a standard location.
