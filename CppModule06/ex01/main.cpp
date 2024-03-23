#include "Serializer.hpp"

int main(void)
{
    Data        data = {"anass"};
    Data        *ptr;
    uintptr_t   raw;

    raw = Serializer::serialize(&data);
    ptr = Serializer::deserialize(raw);

    std::cout << "data  : " << data.content << std::endl;
    std::cout << "ptr   : " << ptr->content << std::endl;


    return 0;
}

