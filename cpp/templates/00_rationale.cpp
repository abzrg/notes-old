/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                           *
 * [  Templates  ] > Rationale                                               *
 *                                                                           *
 *                                                                           *
 * - Reference: All the codes + notes are from Bob Steagall's back-to-basic  *
 * talk on CppCon2021                                                        *
 *                                                                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



// ----------------------------------------------------------------------------
//
// Reuse With Cut-N-Paste I
//
// ----------------------------------------------------------------------------

int
min(int a, int b)
{
  return (a < b) ? a : b;
}

double
min(double a, double b)
{
  return (a < b) ? a : b;
}

string
min(string a, string b)
{
  return (a < b) ? a : b;
}




// ----------------------------------------------------------------------------
//
// Reuse With Cut-N-Paste II
//
// ----------------------------------------------------------------------------

// ... int version

struct int_node
{
    int_node*   next;
    int         value;
};


struct int_list
{
    int_node*   front;
    int_node*   back;
};


void
int_list_append(int_list* l, int val);

void
int_list_prepend(int_list* l, int val);

void
int_list_clear(int_list* l);


// ... double version

struct double_node
{
    double_node*   next;
    double         value;
};


struct double_list
{
    double_node*   front;
    double_node*   back;
};


void
double_list_append(double_list* l, double val);

void
double_list_prepend(double_list* l, double val);

void
double_list_clear(double_list* l);




// ----------------------------------------------------------------------------
//
// Reuse With Type Erasure
//
// ----------------------------------------------------------------------------

#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size,
           int (*compare)(const void *, const void *));


int cmp_double(const void* va, const void* vb)
{
    double a = *((const void*) va);
    double b = *((const void*) vb);

    if (a < b)       return -1;
    else if (a == b) return 0;
    else             return 1;
}


void f()
{
    double double_data[4] = { 3.14159, 1.41421, 2.71828, 1.61803 };

    qsort(&double_data[0], 4u, sizeof(double), &cmp_doube);
}




// ----------------------------------------------------------------------------
//
// Reuse With Type Erasure + Cut-N-Paste
//
// ----------------------------------------------------------------------------

#include <stdlib.h>
#include <string.h>

// ...

int cmp_str(const void* va, const void* vb)
{
    char const* pa = (char const*) va;
    char const* pb = (char const*) vb;

    return strcmp(pa, pb);
}


void g()
{
    string str_data[5] = { "these", "are", "not", "the", "droids" };

    qsort(&str_data[0], 4u, sizeof(string), &cmp_doube); //- ERORR!
}




// ----------------------------------------------------------------------------
//
// Code Reuse With Macros
//
// ----------------------------------------------------------------------------

//  ...
#define BUILD_COMPARE(TYPE)                                                  \
    int cmp_ ## TYPE(const void* va, const void* vb)                         \
    {                                                                        \
        TYPE const* pa = static_cast<TYPE const*>(va);                       \
        TYPE const* pb = static_cast<TYPE const*>(vb);                       \
                                                                             \
        if(*pa < *pb)        return -1;                                      \
        else if (*pa == *pb) return 0;                                       \
        else                 return 1;                                       \
    }


BUILD_COMPARE(float)
BUILD_COMPARE(double)


void h()
{
    float data[4] = { 4.0, 3.0, 2.0, 1.0 };
    qsort(&data[0], 4u, sizeof(float), &cmp_float);  //- OK
    qsort(&data[0], 4u, sizeof(float), &cmp_double); //- ERROR!
}




// ----------------------------------------------------------------------------
//
// Code Reuse
//
// ----------------------------------------------------------------------------

/*

- These problems have been around a "long" time
- In 1970's, some languages began allowing algorithms to be written in terms
  of "types to-be-specified-later"
- Algorithms were then "instantiated" on demand using "type arguments"
- This approach is known as "generic Programming"


             +----------------------------------------------------+
             | C++ supports generic programming with "templates". |
             +----------------------------------------------------+

*/




// ----------------------------------------------------------------------------
//
// What is Generic Programming?
//
// ----------------------------------------------------------------------------

/*

> Generic Programming centers around the idea of abstracting from concrete,
> efficient algorithms to obtain generic algorithms that can be combined with
> different data representations to produce a wide variety of useful software.
>
> -- David Musser, Alexander Stepanov
>    (Generic Programming (1988))



> Following Stepanov, we can define generic programming without mentioning
> language features: "Lift algorithms and data structures from concrete
> examples to their most general and abstract form"
>
> -- Bjarne Stroustrup
>    (Evolving a language in and for the real world: C++ 1991--2006 (2007))

*/

