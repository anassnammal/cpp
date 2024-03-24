#pragma once

template<typename T, typename U, typename V>
void    iter(T *array, U length, V func)
{
    if (!array || !func)
        return ;
    for (U i = 0; i < length; i++)
        func(array[i]);
}