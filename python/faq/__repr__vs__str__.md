## `__str__`

is used when there is implicit/explicit conversion of the object to string.
It should be easy to read, for human consumption

```python
print(my_obj)
formatted_string = "obj: " + str(my_obj)
```


## `__repr__`

is used for representation of the object. It should be unambiguous.


```python
my_obj = MyClass()

# calls my_obj.__repr__()
my_obj
```


## Full example:



```python
class Car:
    def __init__(color: str, mileage: float) -> None:
        self.color = color
        self.mileage = mileage

    # at least implement this
    def __repr() -> str:
        return "{self.__class__.__name__}({self.color}, {self.mileage})".format(self=self)

    def __str() -> str:
        return 

```


```python
import datetime

today = datetime.date.today()

str(today)
# 2023-03-13

today
# datetime.date(2023, 3, 13)

[today, today, today]
# [datetime.date(2023, 3, 13), datetime.date(2023, 3, 13), datetime.date(2023, 3, 13)]
```
