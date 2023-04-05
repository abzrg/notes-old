## `*args` and `**kwargs`


- How it works:

```python
def foo(required, *args, **kwargs):
    print(required)
    if args:
        print(args)   # --> tuple
    if kwargs:
        print(kwargs) # --> dictionary
```

- Writing wrapper function that changes the arguments and passes them (forwarding) to another function.


```python
def foo(x, *args, **kwargs):
    kwargs['name'] = 'Alice'
    new_args = args + ('extra', )  # You need to create a new object
    bar(x, *new_args, **kwargs)
```


- sub-classing -- enhance external class method


```python
class Car:
    def __init__(self, color, mileage):
        self.color = color
        self.mileage = mileage

class AlwaysBlueCar(Car):
    def __init__(self, *args, **kwargs):  # creates ambiguity
        super().__init__(*args, **kwargs)
        self.color = 'blue'
```

- decorators:


```python
...
```

