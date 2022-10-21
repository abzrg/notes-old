## Contents

1. Defining base and derived classes
  - Defining a base class
  - Defining a derived class
  - Conversions and Inheritance
1. Virtual functions
1. Abstract base classes
1. Access control and inheritance
1. Class scope under inheritance
1. Constructor and copy control
  - Virtual destructors
  - Synthesized copy control and inheritance
  - Derived-class copy-control members
  - Inherited constructors
1. Containers and inheritance
  - Writing a basket class
1. 


## Summary

Inheritance lets us write new classes that share behavior with their base
class(es) but override or add to that behavior as needed.
Dynamic binding lets us ignore type differences by choosing, at run time, which
version of a function to run based on an object's dynamic type.
The combination of inheritance and dynamic binding lets us write
type-independent, programs that have type-specific behavior.

In C++, dynamic binding applies only to functions declared as `virtual` and
called through a reference or pointer.

A derived-class object contains a sub-object corresponding to each of its base
classes.
Because every derived object contains a base part, we can convert a reference or
pointer to a derived-class type to a reference or pointer to an accessible base
class.

Inherited objects are constructed, copied, moved, and assigned by
constructing,copying, moving, and assigning the base part(s) of the object
before handling the derived part.
Destructors execute in the opposite order;
the derived type is destroyed first, followed by destructors for the base-class
sub-objects.
Base classes usually should define virtual destructor even if the class
otherwise has no need for a destructor.
The destructor must be virtual if a pointer to a base is ever deleted when it
actually addresses a derived-class object.

A derived class specifies a protection level for each of its base class(es).
Members of a `public` base are part of the interface of the derived class;
members of a `private` base are inaccessible;
members of a `protected` base are accessible to classes that derive from the
derived class but not to users of the derived class.


## Defined Terms

- _Abstract Base Class_: Class that has one or more pure virtual functions. We
  cannot create objects of an abstract class type.

- _Accessible_: Base class member that can be used through a derived object.
  Accessibility depends on the access specifier used in derivation list of the
  derived class and the access level of the member in the base class.
  For example, a `public` member of a class that is inherited via `public`
  inheritance is accessible to users of the derived class.
  A `public` base class member is inaccessible if the inheritance is `private`.

- _base class_:

- _class derivation list_

- _derived class_

- _derived-to-base conversion_

- _direct base class_

- _dynamic binding_

- _dynamic type_

- _indirect base class_

- _inheritance_

- _object oriented programming_

- _override_

- _polymorphism_

- _private inheritance_

- _protected access specifier_

- _protected inheritance_

- _public inheritance_

- _pure virtual_

- _refactoring_

- _run-time binding_

- _sliced down_

- _static type_

- _virtual function_
