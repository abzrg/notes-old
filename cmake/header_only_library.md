
> How to make a header-only library with cmake?

Like this:

```
add_library(project INTERFACE)
target_include_directories(project INTERFACE .)
```


Then in the target that uses the library:

```
target_link_libraries(dependee
    PUBLIC/INTERFACE/PRIVATE # pick one
    project)
```


and include the header like this:

```
#include <project/folder1/file.hpp>
```

[src](https://stackoverflow.com/a/60604878/13041067)


**Worth noting**: Since `CMake 3.19` interface libraries can be created with source files, i.e. `add_library(project INTERFACE file1.hpp file2.hpp)`. If you are working with Visual Studio, those headers will now show up under the generated project. – 
sebrockm
