
```cmake
if (CMAKE_GENERATOR MATCHES "Ninja")
    add_compile_options("-fdiagnostics-color=always")
else()
    # Other stuff
endif()
```

For List of generators refer to: [https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html)
