# To define a meta class derive from 'type' class
class BaseMeta(type):
    def __new__(cls, name, base, body):
        if name != 'Base' and not 'bar' in body:
            raise TypeError("bad user")
        return super().__new__(cls, name, bases, body)


class Base(metaclass=BaseClass):
    """Use BaseClass metaclass to enforce the user of the library to write a
    'bar' method in their derived classes (enforcing the constrain from the base
    class to derived class).

    NOTE: using a try-except block is possible but that is done during runtime
    """
    def foo(self):
        return self.bar

    # You can also enforce constrain using the following dunder method that
    # allows you to hook into the creation of subclasses
    def __init_subclass__(self, *a, **kw):
        """
        __init_subclass__(...) method of builtins.type instance
            This method is called when a class is subclassed.
            The default implementation does nothing. It may be
            overridden to extend subclasses.
        """
        print('__init_subclass__', a, kw) # to see what is passed to this function
        return super().__init_subclass__(*a, **kw)



# Possible, certainly, but not practical!
#
# There is a low level runtime call (disassembly) named: 'LOAD_BUILD_CLASS'. The
# corresponding dunder method is '__build_class__' which let's you to hook into
# the process of building a class (here building the derived classes)
if None:
    old_bc = __build_class__
    def my_bc(fun, name, base=None, **kw):
        if base is Base:
            print('check if bar method is defined')
        if base is not None:
            return old_bc(fun, name, base, **kw)
        return old_bc(fun, name, base, **kw)

    import builtins
    builtins.__build_class__ = my_bc
