# Qualifiers effect on return type


`const` and `volatile` qualifiers of function return types, _when the function
returns by value_, have no meaning because conceptually the returned value is
either discarded or used as a temporary for initialization of an object on the
caller's side. `const`/`volatile` qualification of that object is in the caller's
jurisdiction. For example, it is perfectly legal to initialize a `mutable int`
variable from a function call that returns `const int`.

## Resources:

- https://stackoverflow.com/a/60212564/13041067
