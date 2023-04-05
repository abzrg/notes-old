# Callable Instances

Occasionally we would like to have a function that maintains some state, usually behind the scenes, between the calls.

One example of usage of this need is to __cache function results__. In other words implementing a caching policy to improve performance.

```
           function(arguments)
                    |
 [Return]           |
 [cached]           |
 [value ]           |             No   [calculate]   [Populate]
    |      <arguments in cache?> ------[ results ]---[ cache  ]
    |         /                                          |
    |        / yes                                       |
    |       /                                            |
    +<--(cache)<-----------------------------------------+
```

There are several ways of implementing such stateful function in Python, one of which is `__call__()`

`__call__` allows instance of classes to be callable objects.
`__call__` is invoked on objects when they are called like functions.


```python
# resolver.py
# Caching resolver

import socket

class Resolver:
    def __init__(self):
        self._cache = {}

    def __call__(self, host):
        if host not in self._cache:
            self._cache[host] = socket.gethostbyname(host)
        return self._cache[host]


# -- test

from resolver import Resolver
resolver = Resolver()
resolver("google.com")  # -> '216.239.38.120'

resolver__call__("google.com")  # -> '216.239.38.120'
resolver._cache # -> {'google.com': '216.239.38.120'}

resolve("youtube.com") # -> '10.10.34.36'
resolver._cache # -> {'google.com': '216.239.38.120', 'youtube.com': '10.10.34.36'}


# -- time calls

from timeit import timeit

# timeit
#
# @setup:  any setup operations here
# @stmt:   the code that the elapsed time will be reported for
# @number: how many times code under test will be run (we're
#          testing a cache so it is important that we set that
#          to 1)
#
# __main__: repl namespace

timeit(setup="from __main__ import resolve", stmt="resolve('yahoo.com')", number=1) # -> 0.07126112503465265

timeit(setup="from __main__ import resolve", stmt="resolve('yahoo.com')", number=1) # -> 1.0957999620586634e-05
```


Since callable instances are just normal class instances,
their classes can define any other methods you want.


```python
import socket

class Resolver:
    def __init__(self):
        self._cache = {}

    def __call__(self, host):
        if host not in self._cache:
            self._cache[host] = socket.gethostbyname(host)
        return self._cache[host]

    # 1
    def __clear__(self):
        self._cache.clear()

    # 2
    def has_host(self, host):
        return host in self._cache


# -- test

from resolver import Resolver
```
