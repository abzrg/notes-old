print("\n---------------MyIterable-----------------------\n")


class MyIterable:
    def __init__(self, items):
        self.items = items

    def __iter__(self):
        return MyIterator(self.items)


class MyIterator:
    def __init__(self, items):
        self.index = 0
        self.items = items

    def __next__(self):
        if self.index >= len(self.items):
            raise StopIteration
        value = self.items[self.index]
        self.index += 1
        return value


# create an iterable object
my_iterable = MyIterable([1, 2, 3, 4, 5])

# iterate over the items in the iterable
for item in my_iterable:
    print(item)


print("\n---------------FIBONACCI SEQ-----------------------\n")

class FibonacciSequence:
    def __init__(self, n):
        self.n = n

    def __iter__(self):
        return FibonacciIterator(self.n)

class FibonacciIterator:
    def __init__(self, n):
        self.n = n
        self.current = 0
        self.next = 1
        self.index = 0

    def __next__(self):
        if self.index >= self.n:
            raise StopIteration
        result = self.current
        self.current, self.next = self.next, self.current + self.next
        self.index += 1
        return result


fibonacci_sequence = FibonacciSequence(10)
for number in fibonacci_sequence:
    print(number)

