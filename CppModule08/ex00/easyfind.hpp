#pragma once

#include <algorithm>
#include <iterator>

template<typename T>
typename T::const_iterator easyfind(T const &arr, int target)
{
    return std::find(arr.begin(), arr.end(), target);
}