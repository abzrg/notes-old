# Functions

- A function is fully defined by:
  - name
  - return type
  - parameter types
  - Qualifiers

## Style

- Name funcitons in `CamelCase`
- Use `snake_case` for all function arguments

## declaration and definition

- The name, the argument type (including `&`, `const` etc.) and the return type
  have to be **exactly** the same for declaration and definition

## Use `[[nodiscard]]` attribute (C++17)

```cpp
[[nodiscard]] double SquareNumber(double input);
int main() {
  SquareNumber(4.2); // warning: ignoring return value of function declared with
                     // 'nodiscard' attribute [-Wunused-result]
}
```
## Passing by reference

- Objects are copied by default when passed into functions (the compiler can sometimes avoid the copy)
- **Quick for small objects** (e.g., fundamental types)
- **Slow for bigger objects** (usually any other type)
- **pass bigger objects** by reference to avoid

- The problem with passing by reference is that we are not sure if the object
will be altered in the function implementation or not. The solution is to use
`const` references.
- Avoid using non-`const` references, see Google style

- (from C++11) Returning an object from function is **mostly** fast
- (from C++17) Returning an object from function is **always** fast

- Never Return a reference to a function-local object otherwise it leads to UB.
  - Modern compilers will warn about it

## Overloading

- Writing functions with the same names
- Compiler infers which function to call from input parameters
- **Cannot** overload based on return type
- [All overloads should do semantically the same thing](https://google.github.io/styleguide/cppguide.html#Function_Overloading).

## Default arguments

- Default parameters have a default value:

```c++
void DoSmth(int number = 42);
```

- Only **set in declaration** not in definition
- **Pros**: simplify *some* function calls
- **Cons**:
  - Evaluate upon every call
  - Values are hidden in declaration
  - Can lead to unexpected behavior when overused
  - Gets confusing when having overloaded functions
- [Only use them when readability gets much
better](https://google.github.io/styleguide/cppguide.html#Default_Arguments)
- When all parameters of a constructor have a default value, the constructor
becomes the default constructor.

## References
- 'Code it for yourself' YouTube channel
