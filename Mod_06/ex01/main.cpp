#include "Serializer.hpp"

int main() 
{
    Data data;
    data.value = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << ptr->value << std::endl;

    return 0;
}

