[source](https://stackoverflow.com/a/29121847/13041067)

<!---------------------------------------------------------------------------->
Otherwise, use **opaque/incomplete type**. You'd be surprised to learn how
shockingly few C programmers there are who know how to actually implement 100%
private encapsulation of custom types. This is why there's some persistent myth
about C lacking the OO feature known as private encapsulation. This myth
originates from lack of C knowledge and nothing else.

This is how it goes:

<!---------------------------------------------------------------------------->
`ads1248.h`

```c
typedef struct ads1248_options_t ads1248_options_t; // incomplete/opaque type

ads1248_options_t* ads1248_init (parameters); // a "constructor"
void ads1248_destroy (ads1248_options_t* ads); // a "destructor"
```

<!---------------------------------------------------------------------------->
- `ads1248.c`

```c
#include "ads1248.h"

struct ads1248_options_t {
    uint32_t pin_reset;
    uint32_t pin_drdy;
    uint32_t pin_start;
    volatile avr32_spi_t *spi_module;
    uint8_t cs_id;
};

ads1248_options_t* ads1248_init (parameters)
{
    ads1248_options_t* ads = malloc(sizeof(ads1248_options_t));
    // do things with ads based on parameters
    return ads;
}

void ads1248_destroy (ads1248_options_t* ads)
{
    free(ads);
}
```

<!---------------------------------------------------------------------------->
- `main.c`

```c
#include "ads1248.h"

int main()
{
  ads1248_options_t* ads = ads1248_init(parameters);
  ...
  ads1248_destroy(ads);
}
```

<!---------------------------------------------------------------------------->
Now the code in main cannot access any of the struct members, all members are
100% private. It can only create a pointer to a struct object, not an instance
of it. Works _exactly_ like abstract base classes in C++, if you are familiar
with that. The only difference is that you'll have to call the init/destroy
functions manually, rather than using true constructors/destructors.
