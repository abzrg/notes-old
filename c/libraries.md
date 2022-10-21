# Libraries in C

<!---------------------------------------------------------------------------->
## Static

- It will be baked in to the executable during compile time

- An static library can be build with the following command
  ```sh
  ar rcs libmystaticlib.a $(OBJECT_FILES)
  ```

  - `r`:
  - `c`:
  - `s`:

  - compiler flags for generating object files:
  ```make
  CFLAGS   =  -Wall -Wextra -std=c11 -pedantic -g -fPIC
  ```


<!---------------------------------------------------------------------------->
## Shared Libraries

- It will be linked to executable during runtime

- command to build
  ```sh
  libmylib.so: ${OBJECTS}
      $(CC) ${CFLAGS} ${LDFLAGS} $^ -o $@
  ```

- compiler flags for generating object files:
  ```make
  CFLAGS   =  -Wall -Wextra -std=c11 -pedantic -g -fPIC
  LDFLAGS  =  -shared
  ```


<!---------------------------------------------------------------------------->
## Linking to executable

- To link any library to your program you should set the following variables in
  a Makefile
  ```make
  CPPFLAGS =  -I../path/to/mylib/include/
  CFLAGS   =  -Wall -Wextra -std=c11 -pedantic -g
  LDFLAGS  =  -L../path/to/mylib/lib/
  LDLIBS   =  -lmylib
  ```

- In case of shared libraries you should always set the following environment
  variables

  ```
  # Linux
  export LD_LIBRARY_PATH=/path/to/mylib/:$LD_LIBRARY_PATH

  # Macos
  export DYLD_LIBRARY_PATH=/path/to/mylib/:$LD_LIBRARY_PATH
  ```
