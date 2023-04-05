"""
A decorator is any callable Python object that is used to modify a function,
method or class definition. A decorator is passed the original object being
defined and returns a modified object, which is then bound to the name in the
definition. Python decorators were inspired in part by Java annotations, and
have a similar syntax; the decorator syntax is pure syntactic sugar, using @ as
the keyword:



Let's time our functions

"""

from time import time


def timer(func):
    """
    @func: to be wrapped function.
    """
    def f(x, y=10):
        """Wraps the input function."""
        before = time()
        rv = func(x, y)
        after = time()
        print('elapsed:', after - before)
        return rv
    return f


# A decorator is merely a syntax that is equivalent to
if False: add = timer(add) # hint: off


@timer
def add(x, y=10):
    return x + y


@timer
def sub(x, y=10):
    return x - y



# This is a living thing!
# everything has a runtime representation even 'add'
if False:
    add.__name__
    add.__module__
    add.__defaults__
    add.__code__
    add.__code__.co_code
    add.__code__.co_nlocals
    add.__code__.co_varnames
    import inspect
    inspect.getsource(add)
    inspect.getfilename(add)
