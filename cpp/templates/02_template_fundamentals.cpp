/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                           *
 * [  Templates  ] > Template Fundamentals                                   *
 *                                                                           *
 *                                                                           *
 * - Reference: All the codes + notes are from Bob Steagall's back-to-basic  *
 * talk on CppCon2021                                                        *
 *                                                                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



// ----------------------------------------------------------------------------
//
// Template Terminology
//
// ----------------------------------------------------------------------------


/*

- Discussing templates with clarity means using terminology with precision

- How do we refer to templates used to "generate" classes?
    - classess, structs, and unions are referred to generally as "class types"
    - "class template" indicates a "parameterized descriptions" of family of
    (related) classes

- C++ also provides parameterized descriptions of
    - Functions
    - Member functions
    - Type aliases
    - Variables
    - Lambdas

- The standard treats terms "thing template" consistently
    - "template" is the noun, indicating a parameterized description
    - "thing" is an adjective, specifying the family of things being
    parameterized

- Also, the associated verb is parameterize or parametrize - not termpletize!

*/




// ----------------------------------------------------------------------------
//
// Translation Units
//
// ----------------------------------------------------------------------------


/*

- Compilation
    - The process of converting human-readable source code into binary object
    files
    - From a high-level prespective, there are four stages of compilation:
        - lexical analysis
        - Syntax analysis
        - Semantic analysis
        - Code generation
    - In C++, we typically generate one object file for each source file


- Linking
    - The process of combining object files and binary libraries to make a
    working program


- In C++, translation is performed in nine well-defined stages


- Phases 1 through 6 perform lexical analysis
    - These are what we usually refer to as pre-processing
    - The output of Phase 6 is a translation unit


- A translation unit is defined [5.1] as
    - A source file
    - Plus all the headers and source files included via '#include' directives
    - Minus any source lines skipped by conditional inclusion preprocessing
    directives (#ifdef)
    - And all macros expanded


- Phases 7 and 8 perform syntax analysis, semantic analysis, and codegen
    - These are what we usually refer to as compilation
    - Templates are parsed in Phase 7
    - Templates are instantiated in Phase 8
    - The output is called a translated translation unit (e.g., object code)


- Phase 9 performs program image creation
    - This is what usually think of as linking
    - The ouput is an executable image suitable for the intended execution
    environment

*/




// ----------------------------------------------------------------------------
//
// Phases of Translation (6) -- a Samle TU For Fun
//
// ----------------------------------------------------------------------------


// Hello.h
//========
#ifndef HELLO_H_INC
#define HELLO_H_INC

#include <iostream>

void print_hello();

#endif


// Hello.cpp
//==========
#include "hello.h"

void print_hello()
{
    std::cout << "Hello!" << std::endl;
}


// main.cpp
//=========

#include "hello.h"

int main()
{
    print_hello();
    return 0;
}


/*

- Compilers provide a way to inspect TU contents (or something close to it)
    - With GCC you can use the `-E` flag:

    ```sh
    $ g++ -std=c++20 -E main.cpp  | egrep -v '#' | tee main.i
    $ g++ -std=c++20 -E hello.cpp | egrep -v '#' | tee hello.i
    ```

*/




// ----------------------------------------------------------------------------
//
// Declarations and Definitions
//
// ----------------------------------------------------------------------------


/*

- An 'entity' is one these things:
    - value
    - object
    - reference
    - structured binding
    - function
    - enumerator
    - type
    - class member
    - bit-field
    - template *
    - template specialization *
    - namespace
    - pack


- A 'name' is the use of an identifier that denotes an entity (or label)
    - Every name that denotes an entity is introduced by a 'declaration'


- A 'declaration' introduces one or more 'names' into a translation unit
    - A declaration may also 're-introduce' a name into a translation unit
        - As long as the re-introduction of that name is identical to the
        previous introduction of that name.


- A 'definition' is a declaration that fully defines the entity being introduced


- A 'variable' is an entity introduced by the declaration of an object
    - Or of reference other than a non-static data member


- Every declaration is also a 'definition', unless:
    - It is a function declaration without a corresponding definition of the
    body
    - It is a parameter declaration in a function declaration that is not
    definition
    - It is a declaration of a class name without a corresponding definition
    - It is a template parameter
    - It is a `typedef` declaration
    - It is a `using` declaration
    - It contains the `extern` specifier
    - And a few other cases


- The set of definitions is a proper subset of the set of declarations

*/


// -- Declaration

extern int       a;
extern int const c;


int f(int);


class Foo;


using N::d;


struct Bar
{
    int compute_x(int y, int z);
};


using bar_vec = std::vector<Bar>; // Also a definition


typedef int Int; // Also a definition



// ~~~



// -- Definition

extern int       a = 0;
extern int const c = 37;


int f(int)
{
    return x + 1;
}


clas Foo
{
    int mval;

public:
    Foo(in x) : mval(x) {}
};


namespace N { int d; }


int Bar::compute_x(int y, int z)
{
    return (y + z) * 3;
}




// ----------------------------------------------------------------------------
//
// Template Declarations and Definitions
//
// ----------------------------------------------------------------------------

template<class T>
T const& max(T const &, T const& b); //- Declaration of function template max

template<class T>
T const& max(T const &, T const& b) //- Definition of function template max
{
    return (a > b) ? a : b;
}


// ...


template<class T1, class T2>
struct pair;                        //- Declaration of class template pair

template<class T1, class T2>
struct pair
{
    T1 first;
    T2 second;
    // ...
};


// ...


template<class T, class Alloc = allocator<T>>
class vector
{
public:
    // ...

    using iterator       = /*...*/;
    using const_iterator = /*...*/;

    // ...

    template<class InputIter>              //- Declaration of member function template insert
    iterator insert(const_iterator pos, InputIter first, InputIter last);

  // ...
};

template<class T, class Alloc>
template<class InputIter> auto
vector<T, Alloc>::insert(const_iterator pos, InputIter first, InputIter last)
{ /*...*/ }


// Or we can put the definition inside the class

template<class T, class Alloc = allocator<T>>
class vector
{
public:
    // ...

    using iterator       = /*...*/;
    using const_iterator = /*...*/;

    // ...

    template<class InputIter>              //- Definition of member function template insert
    iterator insert(const_iterator pos, InputIter first, InputIter last)
    { /*...*/ }

  // ...
};


// ...


template<class Key, class Val>
using my_map = map<Key, Val, greater<Key>>;  //- Declaration of alias template my_map


template<class T>
constexpr T pi = T(3.1415926535897932385L); //- Declration of variable template pi




// ----------------------------------------------------------------------------
//
// The One-Definition Rule (ODR)
//
// ----------------------------------------------------------------------------

/*

- A given translation unit can contain at most one definition of any:
    - variable
    - function
    - class type
    - enumeration type
    - template *
    - default argument for a parameter for a function in a given scope
    - default template argument *

- Ther may be multiple declarations, but "there can only be one
  definition"

- A program must contain exactly one definition of every non-inline
  variable or function that is used in the program
    - Multiple declarations are OK, but only one definition

- For an inline variable or an inline function, a definition is required in every translation unit that uses it
    - inline was originally a suggested optimization made to the compiler
    - It has now evolved to mean "multiple definitions are permitted"

- Exactly one definition of a class must appear in any translation unit that uses it in such a way that the clas must be complete


* The same rules for inline variables and function also apply to templates


- My simple guidelines for observing ODR:
    - For an `inline` thing (variable or function) that get used in a translation unit, make sure it is defined at least once somewhere somewhere in that translation unit.
    - For a non-`inline`, non-`template` thing that gets used, make sure it is defined exactly once in across all translation units
    - For a `template` thing, define it in a header file, include the header where the thing is needed, and let the tool-chain decide where it is defined
    - Except in rare circumstances where finer control is required

*/




// ----------------------------------------------------------------------------
//
// Template Parameters and Template Arguments
//
// ----------------------------------------------------------------------------

template<class T1, class T2,>  // T1 and T2: Template args
struct pair  // pair is template
{
    T1 first;
    T2 second;
    // ...
};

template<class T>  // T: template arg
T const& max(T const& a, T const& b) // max is template
{ /*...*/ }


// ~~~


// my_pair: specialization
pair<string, double> my_pair; // Template params: string, double

// max: specialization
double d = max<double>(0, 1); // Template param: double

string s1 = /*...*/;
string s2 = /*...*/;
string s3 = max(s1, s2); // Template param (deduced): string; max: specialization


/*

- Template parameters are the names that come after the `template` keyword in a template declaration

- Template arguments are the concrete items "substituted" for the template parameters to create a template "specialization"

*/




// ----------------------------------------------------------------------------
//
// Template Parameters
//
// ----------------------------------------------------------------------------

/*

- Template parameters come in three flavors
    - Type parameters
    - Non-type template parameters (NTTPs)
    - Template-template parameters

- Type parameters
    - Most common
    - Declared using the `class` or type `typename` keyword

*/


template<class T1, class T2> struct pair;
template<typename T1, typename T2> struct pair;

template<class T>    T max(T const& a, T const& b);
template<typename T> T max(T const& a, T const& b);




// ----------------------------------------------------------------------------
//
// Non-Type Template Parameters (NTTPs)
//
// ----------------------------------------------------------------------------


// Template parameters don't have to be types:

template<class T, size_t N>
class Array
{
    T m_data[N];
    // ...
};

Array <foobar, 10> some_foobars;


// ...


template<int Incr>
int IncrementBy(int val)
{
    return val + Incr;
}

int x = /*...*/;
int y = IncrementBy<42>(x);


// NTTPs denote constant values that can be determined at compile or link time, and their type must be
//    - An integer or enumeration type (most common)
//    - A pointer or pointer-to-member type
//    - std::nullptr_t
//    - And a couple of other things...




// ----------------------------------------------------------------------------
//
// Template-Template Parameters
//
// ----------------------------------------------------------------------------

// Template parameters can themselves be templates
//    - Placeholders for class or alias templates
//    - Declared like class templates, but only the `class` and `typename` keywords can be used

#include <vector>
#include <list>

template<class T, template<class U, class A = std::allocator<U>> clas C>
struct Adaptor
{
    C<T> my_data;
    void push_back(T const& t) { my_data.push_back(t); }
};

Adaptor<int, std::vector>  a1;
Adaptor<long, std::list>   a2;

a1.push_back(0);
a2.push_back(1);




// ----------------------------------------------------------------------------
//
// Default Template Arguments
//
// ----------------------------------------------------------------------------

// Template parameters can have default arguments

template<class T, class Alloc = allocator<T>>
class vector { /*...*/ };

template<class T, size_t N = 32>
class Array { /*...*/ };

template<class T, template<class U, class A = allocator<U>> class C = vector>
struct Adaptor { /*...*/ };


vector<double> vec; //- std::vector<double, std::allocator<double>>
Array<long>    arr; //- Array<long, 32>
Adaptor<int>   adp; //- Adaptor<int, std::vector<int, std::allocator<int>>>


// Default arguments must occur at the end of the list for class, alias, and variable templates

template<class T0, class T1=int, class T2=int, class T3=int>
class quad;  //- OK

template<class T0, class T1=int, class T2=int, class T3=int, class T4>
class quint; //- Error


// Function templates don't have this requirement
//    - Template type deduction can determine the template parameters

template<class RT=void, class T>
RT* address_of(T& value)
{
    return static_cast<RT*>(&value);
}




// ----------------------------------------------------------------------------
//
// Specialization
//
// ----------------------------------------------------------------------------

/*

- The concrete entity resulting from "substituting" arguments for template parameters is a specialization
- These entities are named, and the name has the syntactic form

    ```
    template-name<argument-list>
    ```

    - This name is formally called a 'template-id'

*/


//- pair is a class template
template<class T1, class T2>
struct pair
{
    T1 first;
    T2 second;
    // ...
};

//- max is a function template
template <class T>
T const& max(T const& a, T const& b)
{ /*...*/ }


// ~~~


//- pair<string, double>: name of specialization
pair<string, double> my_pair;

//- max<double>: name of specialization
double d = max<double>(0, 1);

//- max<string>: name of specialization
string s1 = /*...*/;
string s2 = /*...*/;
string s3 = max(s1, s2);




// ----------------------------------------------------------------------------
//
// From Template to Specialization
//
// ----------------------------------------------------------------------------

/*

- The template is a recipe that tells how to generate something useful
- A specialization is the useful thing built from that recipe
- Q: How do we get from template to specialization?
- A1: Instantiation
- A2: Explicit specialization

*/




// ----------------------------------------------------------------------------
//
// Instantiation
//
// ----------------------------------------------------------------------------

/*

- At some point we'll want to use the recipe and make a thing
    - Most of the time the compiler knows how to cook the recipe for us

- At various times, the compiler will 'substitute' concrete (actual) template arguments for the template parameters used by a template

- Sometimes this substitution is tentative
    - The compiler checks to see if a possible substitution could be valid

- Sometimes the result of this substitution is used to create a specialization...

- "Template instatiation" occurs when 'the "compiler" substitutes template arguments for template parameters' in order to define an entity
    - I.e., generate a specialization of some template

- The specialization from instantiating a class template is sometimes called (informally) an 'instantiated class'
    - Likewise for the other template categories (instantiated function, etc.)
    - These are also informally called instantiations

- Template instantiation can occur in two possible ways
    - Implicitly
    - Explicitly

*/




// ----------------------------------------------------------------------------
//
// Instantiation and Sepcialization
//
// ----------------------------------------------------------------------------

/*

- What are the relationship between instantiation and specialization?

NB: arrow means 'is-A'

* Diagram courtesy of Dan Saks
  Back to Basics: Function and Class Templates CppCon 2019

                      +----------------+
                      | Specialization |
                      +----------------+
                        ^
                       /
            +---------------+
            | Instantiation |
            +---------------+
                 ^
                /
        +---------------+
        | Instantiation |
        +---------------+

*/




// ----------------------------------------------------------------------------
//
// Implicit Instantiation
//
// ----------------------------------------------------------------------------

/*

- In general, when the compiler sees the use of a specialization in code, it will create the specialization by subtituting template arguments for parameters
    - This is totally automatic, requiring no guidance from the code

- This is called 'implicit', 'on-demand', or 'automatic' instantiation
    - The compiler decides where, when, and how much of the specialization to create

    ```C++
    pair<string, double> my_pair;

    double d = max<double>(0, 1);

    string s1 = ...;
    string s2 = ...;
    string s3 = max(s1, s2);
    ```

- For class templates, implicit instantiation doesn't necessarily instantiate all the member of the class
    - The compiler might not generate non-virtual functions or static data members
    - Consider

    ```C++
    void f()
    {
        vector<int> v{1, 2};
    }
    ```

    - The only things that are going to be instantiated are
        - Constructor
        - The private implementations that are necessary to carry out the constructor
        - Destructor

    - `append`, indexing, `insert`, etc. are not going to be generated; Only the stuff that are actually needed to run `f` is goning to be instantiated

*/