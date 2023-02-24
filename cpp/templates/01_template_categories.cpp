/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\
 *                                                                           *
 * [  Templates  ] > Template Categories                                     *
 *                                                                           *
 *                                                                           *
 * - Reference: All the codes + notes are from Bob Steagall's back-to-basic  *
 * talk on CppCon2021                                                        *
 *                                                                           *
\* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



// ----------------------------------------------------------------------------
//
// Function Templates (C++98/03)
//
// ----------------------------------------------------------------------------

// Recipe for making functions

template<class T>
T const& min(T const& a, T const& b);
{
    return (a < b) ? a : b;
}

template<class T>
void swap(T& a, T& b);

template<class RandomIt, class Compare>
void sort(RandomIt first, RandomIt last, Compare comp);




// ----------------------------------------------------------------------------
//
// Class Templates (C++98/03)
//
// ----------------------------------------------------------------------------

// Recipe for making classes

template<class T, size_t N>
struct array
{/*...*/};


template<class T, clas Alloc = allocator<T>>
class vector
{/*...*/};


template<class Key, class Val,
         class Compare = less<Key>,
         class Allocator = allocator<pair<const Key, T>>>
class map
{/*...*/};




// ----------------------------------------------------------------------------
//
// Member Function Templates (C++98/03)
//
// ----------------------------------------------------------------------------

// Recipes for making member functions

template<class T, clas Alloc = allocator<T>>
class vector
{
public:
    // ...

    using iterator       = /*...*/;
    using const_iterator = /*...*/;

    // ...

    template<class InputIter>
    iterator insert(const_iterator pos, InputIter first, InputIter last)
    {/*...*/}

    // ...
};




// ----------------------------------------------------------------------------
//
// Alias Templates (C++11)
//
// ----------------------------------------------------------------------------

// Recipe for making type aliases

template<class T>
using sa_vector = vector<T, my_special_allocator<T>>;

sa_vector<flaot>    fv;


template<class Key, class Val>
using my_map = map<Key, Val, gerator<Key>>;

my_map<string, int> msi;


template<class T, ptrdiff_t C, class A = std::allocator<T>, class CT = void>
using general_row_vector =
    basic_matrix<matrix_storage_engine<T, extents<1,C>, A,
                 matrix_layout::row_major>, CT>;

general_row_vector<double, 20>  rv;




// ----------------------------------------------------------------------------
//
// Variable Function Templates (C++14)
//
// ----------------------------------------------------------------------------

// Recipes for making variables or static data members

template<class T>
inline constexpr T pi = (3.1415926535897932385L);

template<class T>
T circular_area(T r) { Return pi<T> * r * r; }


template<class T>
inline constexpr bool is_arthimetic_v = is_arithmetic<T>::value;

void init(T* p, size_t N)
{
    if constexpr (is_arithmetic_v<T>)
        memcpy(p, 0, sizeof(T) * N);
    else
        unintialized_fill_n(p, N, T());
}




// ----------------------------------------------------------------------------
//
// Lambda Templates (C++20)
//
// ----------------------------------------------------------------------------

// Recipe for making lambdas

auto multiply = []<class T>(T a, T b) { return a * b; };

auto d0 = multiply(1.0, 2.0);

