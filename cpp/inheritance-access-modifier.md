# Access modifier (inheritance)

- Class by default inherit privately
- Struct by default inherit publicly

```cpp
struct A { int i = 0; };
class B : public A { };
class C : A { };
int main() {
    B b;
    C c;
    b.i = 2;
    c.i = 3;  // ERROR, i is a private member of A
}
```

- No matter what the access modifier for inheritance is, the public and
  protected members of the base class are accessible inside the derived class
- inheritance access modifier only specifies what member can be accessed from
the outside the class
- The access modifier sets the least access level (from outside)
  - public: base class members can be at least public (if they are)
  - protected: base class members can be at least protected (even if they are
  public they convert to protected inside the derived class)

```cpp
class A
{
    public:
       int x;
    protected:
       int y;
    private:
       int z;
};

class B : public A
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A    // 'private' is default for classes
{
    // x is private
    // y is private
    // z is not accessible from D
};
```

- public:
  - base(public) -> derived(public)
  - base(protected) -> derived(protected)
  - base(private) -> none

- protected:
  - base(public) -> derived(protected)
  - base(protected) -> derived(protected)
  - base(private) -> none

- private:
  - base(public) -> derived(private)
  - base(protected) -> derived(private)
  - base(private) -> none

## Resources

1. https://stackoverflow.com/a/1372858/13041067
1. https://stackoverflow.com/a/30696123/13041067
