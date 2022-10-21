An **opaque** pointer is one in which no details are revealed of the underlying
data (from a dictionary definition: opaque: adjective; not able to be seen
through; not transparent).

For example, you may declare in a header file (this is from some of my actual
code):

```c
typedef struct pmpi_s *pmpi;
```

which declares a type `pmpi` which is a pointer to the opaque structure struct
`pmpi_s`, hence anything you declare as `pmpi` will be an opaque pointer.

Users of that declaration can freely write code like:

```c
pmpi xyzzy = NULL;
```

without knowing the actual "definition" of the structure.

Then, in the code that knows about the definition (i.e., the code providing the
functionality for `pmpi` handling, you can "define" the structure:

```c
struct pmpi_s {
    uint16_t *data;     // a pointer to the actual data array of uint16_t.
    size_t sz;          // the allocated size of data.
    size_t used;        // number of segments of data in use.
    int sign;           // the sign of the number (-1, 0, 1).
};
```

and easily access the individual fields of it, something that users of the
header file cannot do.

More information can be found on the
[Wikipedia page](http://en.wikipedia.org/wiki/Opaque_pointer)
for opaque pointers..

The main use of it is to hide implementation details from users of your library.
Encapsulation (despite what the C++ crowd will tell you) has been around for
a long time :-)

You want to publish just enough details on your library for users to effectively
make use of it, and no more. Publishing more gives users details that they may
come to rely upon (such as the fact the size variable `sz` is at a specific
location in the structure, which may lead them to bypass your controls and
manipulate it directly.

Then you'll find your customers complaining bitterly when you change the
internals. Without that structure information, your API is limited only to what
you provide and your freedom of action regarding the internals is maintained.
