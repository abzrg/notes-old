# Does importing modules causes any overhead?

Importing modules in Python can cause some overhead, but the impact is usually
negligible.

When you import a module in Python, the interpreter has to read and parse the
contents of the module file, and then execute any top-level code (such as
function or class definitions) in the module. This process can take some time,
especially for large modules or modules with complex dependencies.

However, once a module is imported, subsequent imports of the same module will
not incur the same overhead. Python keeps a cache of imported modules, so if
a module has already been imported, the interpreter can simply look it up in the
cache instead of reading and parsing the file again.

In most cases, the overhead of importing a module is negligible compared to the
overall execution time of a Python program. However, in some cases where
performance is critical, it may be worth taking steps to minimize the number of
module imports or to optimize the import process. For example, you could use
tools like `importlib` to import modules more efficiently, or you could use a tool
like `PyInstaller` to package your Python code and its dependencies into a single
executable, which can reduce the overhead of module imports.

src: chatgpt
