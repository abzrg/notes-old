# Notes Relate to Object Oriented

<!--  -->

## `@staticmethod` vs `@classmethod`

In Python, both static and class methods are used to define methods that can be
called on a class instead of an instance. However, they are different in terms
of their behavior and purpose.

A static method is a method that belongs to a class but doesn't have access to
the instance or class itself. This means that it can't modify the instance or
class state. A static method is typically used when you need to define a method
that is related to a class but doesn't depend on the instance state. Static
methods can be defined using the `@staticmethod` decorator.

Here's an example of a static method:

```python
class MyClass:
    @staticmethod
    def my_static_method(x, y):
        return x + y

# Call static method without instance
result = MyClass.my_static_method(2, 3)
print(result)  # Output: 5
```

On the other hand, a class method is a method that belongs to a class and has
access to the class itself through the `cls` parameter. This means that a class
method can modify the class state. Class methods are typically used when you
need to define a method that is related to a class and needs to access or modify
the class state. Class methods can be defined using the `@classmethod` decorator.

Here's an example of a class method:

```python
class MyClass:
    count = 0

    def __init__(self):
        MyClass.count += 1

    @classmethod
    def get_count(cls):
        return cls.count


# Call class method without instance
result = MyClass.get_count()
print(result)  # Output: 0

# Create instances of class to modify class state
obj1 = MyClass()
obj2 = MyClass()
result = MyClass.get_count()
print(result)  # Output: 2
```

In summary, static methods are used when you want to define a method that is
related to a class but doesn't depend on the instance state, while class methods
are used when you want to define a method that is related to a class and needs
to access or modify the class state.

src: chatgpt

<!--  -->

## Class attributes

In Python, a class attribute is a variable that is defined __in a class__ and is
__shared among all instances of that class__. Class attributes are also sometimes
called _class-level variables_ or _static variables_.

When a class attribute is accessed or modified by any instance of that class,
it is actually accessing the same variable that is shared across all
instances. This means that any changes made to a class attribute will be visible
to all instances of that class.

Here's an example of defining and accessing a class attribute in Python:

```python
class MyClass:
    class_attribute = 42

    def __init__(self, instance_attribute):
        self.instance_attribute = instance_attribute

# Accessing class attribute
print(MyClass.class_attribute)  # Output: 42

# Modifying class attribute
MyClass.class_attribute = 10
print(MyClass.class_attribute)  # Output: 10

# Accessing class attribute from an instance
obj = MyClass(100)
print(obj.class_attribute)  # Output: 10

# Modifying class attribute from an instance
obj.class_attribute = 20
print(obj.class_attribute)  # Output: 20
print(MyClass.class_attribute)  # Output: 10
```

In the example above, `class_attribute` is a class attribute that is defined in
the `MyClass` class. It is accessed and modified directly using the class name
`MyClass`, and any changes made to it are visible to all instances of that class.

Note that when you __modify/assign__ a class attribute using an __instance__ of the class
(as shown in the last two lines of the example), a new instance attribute is
created with the same name. This means that the __instance attribute takes
precedence over the class attribute (only) for that instance__, but the class attribute
remains unchanged and is still shared across all instances of the class.

<!--  -->
