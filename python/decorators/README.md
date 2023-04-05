# Decorators

A decorator is any callable Python object that is used to modify a function,
method or class definition. A decorator is passed the original object being
defined and returns a modified object, which is then bound to the name in the
definition. Python decorators were inspired in part by Java annotations, and
have a similar syntax; the decorator syntax is pure syntactic sugar, using @ as
the keyword:

``` python
@viking_chorus
def menu_item():
    print("spam")
```

is equivalent to

``` python
def menu_item():
    print("spam")
menu_item = viking_chorus(menu_item)
```

Decorators are a form of metaprogramming; they enhance the action of the
function or method they decorate. For example, in the sample below,
`viking_chorus` might cause `menu_item` to be run 8 times (see Spam sketch) for each
time it is called:


Decorators are a form of metaprogramming; they enhance the action of the
function or method they decorate. For example, in the sample below,
`viking_chorus` might cause `menu_item` to be run 8 times (see Spam sketch) for each
time it is called:

``` python
def viking_chorus(myfunc):
    def inner_func(*args, **kwargs):
        for i in range(8):
            myfunc(*args, **kwargs)
    return inner_func
```


Canonical uses of function decorators are for creating class methods or static
methods, adding function attributes, tracing, setting pre- and postconditions,
and synchronization, but can be used for far more, including tail recursion[^1]
elimination, memoization[^2] and even improving the writing of other
decorators.

[^1]: In computer science, a tail call is a subroutine call performed as the final
  action of a procedure. If the target of a tail is the same subroutine, the
  subroutine is said to be tail recursive, which is a special case of direct
  recursion.

[^2]: In computing, memoization or memoisation is an optimization technique used
  primarily to speed up computer programs by storing the results of expensive
  function calls and returning the cached result when the same inputs occur again.

Decorators can be chained by placing several on adjacent lines:

``` python
@invincible
@favourite_colour("Blue")
def black_knight():
    pass
```

is equivalent to

``` python
def black_knight():
    pass
black_knight = invincible(favourite_colour("Blue")(black_knight))
```

or, using intermediate variables

``` python
def black_knight():
    pass
blue_decorator = favourite_colour("Blue")
decorated_by_blue = blue_decorator(black_knight)
black_knight = invincible(decorated_by_blue)
```

In the example above, the `favourite_colour` _decorator factory_ takes an
argument. Decorator factories __must return a decorator__, which is then called with
the object to be decorated as its argument:

``` python
def favourite_colour(color):
    def decorator(func):
        def wrapper():
            print(color)
            func()
        return wrapper
    return decorator
```

This would then decorate the `black_knight` function such that the color, `"Blue"`,
would be printed prior to the `black_knight` function running. _Closure_ ensures
that the color argument is accessible to the innermost wrapper function even
when it is returned and goes out of scope, which is what allows decorators to
work.

Despite the name, Python decorators are not an implementation of the decorator
pattern. The decorator pattern is a design pattern used in statically-typed
object-oriented programming languages to allow functionality to be added to
objects at run time; Python decorators add functionality to functions and
methods at definition time, and thus are a higher-level construct than
decorator-pattern classes. The decorator pattern itself is trivially
implementable in Python, because the language is duck typed, and so is not
usually considered as such.

# Reference

- [Python Syntax and Semantics](https://en.wikipedia.org/wiki/Python_syntax_and_semantics#Decorators)

