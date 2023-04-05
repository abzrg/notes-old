#include <vector>
#include <iterator> // distance
#include <functional> // greater<T>
#include <algorithm>

int main()
{
    std::vector<int> v = { 7, 5, 3, 1 };
    bool is_found = std::binary_search(v.begin(), v.end(), std::greater<int>());
    (void)std::distance(v.begin(), v.end());
    return 0;
}
