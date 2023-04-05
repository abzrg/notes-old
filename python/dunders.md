Checkout Python's data model for more.


```python
def __contains(self, item): -> bool:
    ...

def __iter__(self): -> Iterator[Generic[T]]:
    ...

def __repr__(self) -> str:
    ...

def __str__(self) -> str:
    ...

def __len__(self): -> int:
    ...

def __add_(self, other) -> f'{self.__class__.__name__}':
    ...

def __next__(self) -> someValue:
    # check for `StopIteration` exception
    ...

```


