# Constructor calls in inheritance

## Order

- Construction: first base and then derived
- Destruction: first derived and then base


```cpp
class Base
{
public:
    int m_id {};

    Base(int id=0)
        : m_id{ id }
    {
    }

    int getId() const { return m_id; }
};

class Derived: public Base
{
public:
    double m_cost {};

    Derived(double cost=0.0)
        : m_cost{ cost }
    {
    }

    double getCost() const { return m_cost; }
};
```

## Non-derived class construction

1. Memory for base is set aside
1. The appropriate Base constructor is called
1. The member initializer list initializes variables
1. The body of the constructor executes
1. Control is returned to the caller


## Derived class construction

1. Memory for derived is set aside (enough for both the Base and Derived
portions)
1. The appropriate Derived constructor is called
1. The Base object is constructed first using the appropriate Base constructor.
**If no base constructor is specified, the default constructor will be used.**
1. The member initializer list initializes variables
1. The body of the constructor executes
1. Control is returned to the caller

NOTE: we cannot hope the compiler use the base class constructor to construct
the derived object. For example:

```cpp
class Base {
  int m_i;
public:
  Base() = default;
  Base(int i) : m_i{i} { }
};

class Derived : public Base {
public:
  Derived() { };
};

int main() {
  Derived d{2};  // Error, No matching constructor for initialization of 'Derived'
}
```

NOTE: we cannot skip levels of inheritance and call the constructor for the base
of the base class (child calling grandpa!)
- It is worth mentioning that constructors can only call constructors from their
immediate parent/base class.

```cpp
#include <string>

class GrandParent {
  std::string m_name;
public:
  GrandParent(std::string name = "") {}
};
class Parent : public GrandParent {
public:
  Parent() = default;
  Parent(int j = 0) {}
};
class Child : public Parent {
public:
  Child(): GrandParent("asdf") {}  // ERROR: Type 'GrandParent' is not a direct or virtual base of 'Child'
};

int main() {
  Child c;
}
```

## Initializing base class members

- C++ prevents classes from initializing inherited member variables in the
member initializer list of a constructor.
- In other words, the value of a member variable can only be set in a member
initializer list of a constructor belonging to the same class as the variable.
- Because `const` variables must be initialized with a value at the time of
creation, the base class constructor must set its value when the variable is
created. However, when the base class constructor finishes, the derived class
constructor’s member initializer lists are then executed.
- Each derived class would then have the opportunity to initialize that
variable, potentially changing its value! By restricting the initialization of
variables to the constructor of the class those variables belong to, C++
ensures that all variables are initialized only once.

```cpp
class Derived: public Base
{
public:
    double m_cost {};
    Derived(double cost=0.0, int id=0)
        // does not work
        : m_cost{ cost }
        , m_id{ id }
    {
    }
...
};
```

- However, inherited (`non-const` and `non-reference`) variables can still have
their values changed in the body of the constructor using an assignment.
Consequently, new programmers often also try this:

```cpp
class Derived: public Base
{
public:
    double m_cost {};
    Derived(double cost=0.0, int id=0)
        : m_cost{ cost }
    {
        m_id = id;
    }
...
};
```

Problems:
1. Does not work if `m_id` were a `const` or reference.
  - Because `const` and references have to be initialized in the member
  initializer list of the constructor.
1. It’s also inefficient because `m_id` gets assigned a value twice:
  - once in the member initializer list of the Base class constructor
  - and then again in the body of the Derived class constructor.
1. And finally, what if the Base class needed access to this value during
 construction? It has no way to access it, since it’s not set until the
 Derived constructor is executed (which pretty much happens last).

- In construction of the derived object, the construction of the base is by
default done via the **base default constructor**. To use another base
constructor we need to explicitly call the desired base constructor in the
member initializer list of the derived class.
  - A default constructor is a constructor which can be called with no arguments
  (either defined with an empty parameter list, or with default arguments
  provided for every parameter). A type with a public default constructor is
  `DefaultConstructible`.
  - In this case what happens is we have a default initialization. This happens
  when a base class or a non-static data member is not mentioned in
  a constructor initializer list and that constructor is called.[cppref]

- NOTE: If we don't explicitly specify the base constructor in the derived class
and don't code the default base constructor in the base class we get the
following error:

> Constructor for derived class must explicitly initialize the base class which
> does not have a default constructor

- NOTE: it doesn't matter where in the Derived constructor member initializer
list the Base constructor is called -- it will always execute first.



```cpp
class Derived: public Base
{
public:
    double m_cost {};
    Derived(double cost=0.0, int id=0)
        : Base{ id } // Call Base(int) constructor with value id!
        , m_cost{ cost }
    {
    }
    double getCost() const { return m_cost; }
};
```


```cpp
#include <iostream>

int main()
{
    Derived derived{ 1.3, 5 }; // use Derived(double, int) constructor
    std::cout << "Id: " << derived.getId() << '\n';  // 5
    std::cout << "Cost: " << derived.getCost() << '\n';  // 1.3

    return 0;
}
```

1. Memory for derived is allocated.
1. The Derived(double, int) constructor is called, where cost = 1.3, and id = 5.
1. The compiler looks to see if we've asked for a particular Base class constructor. We have! So it calls Base(int) with id = 5.
1. The base class constructor member initializer list sets `m_id` to 5.
1. The base class constructor body executes, which does nothing.
1. The base class constructor returns.
1. The derived class constructor member initializer list sets `m_cost` to 1.3.
1. The derived class constructor body executes, which does nothing.
1. The derived class constructor returns.

## References

1. [17.4 — Constructors and initialization of derived classes](https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/)
1. [Default constructor (cppreference)](https://en.cppreference.com/w/cpp/language/default_constructor)
