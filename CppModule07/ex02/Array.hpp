#pragma once

#include <iostream>

template<typename T>
class Array
{
    T               *content;
    unsigned int    length;

public:
    Array(void) : content(nullptr), length(1)
    {
        try
        {
            content = new T();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    Array(unsigned int n) : content(nullptr), length(n)
    {
        try
        {
            content = new T[length];
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    Array(Array const &src) : content(nullptr), length(0)
    {
        *this = src;
    }

    ~Array(void)
    {
        delete[] content;
    }

    unsigned int    size(void) const
    {
        return (length);
    }

    Array   &operator=(Array const &rhs)
    {
        if (this != &rhs)
        {
            try
            {
                unsigned int size = rhs.size();
                T   *tmp = new T[size];

                delete[] content;
                length = size;
                content = tmp;
                for (unsigned int i = 0; i < length; i++)
                    content[i] = rhs[i];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
        return (*this);
    }

    T   &operator[](unsigned int i)
    {
        if (i >= length)
            throw std::out_of_range("Array index out of bounds");
        return content[i];
    }

    T const   &operator[](unsigned int i) const
    {
        if (i >= length)
            throw std::out_of_range("Array index out of bounds");
        return content[i];
    }
};

template <typename T>
std::ostream    &operator<<(std::ostream &o, Array<T> const &src)
{
    unsigned int size;

    size = src.size();
    for (unsigned int i = 0; i < size; i++)
        o << src[i] << ' ';
    return (o);
}