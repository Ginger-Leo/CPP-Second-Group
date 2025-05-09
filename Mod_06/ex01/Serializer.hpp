#pragma once
#include <iostream>

class Serializer
{
    private:
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);

    protected:

    public:
        Serializer();
        ~Serializer();
        Serializer(Serializer&) = delete;
        Serializer& operator=(const Serializer&) = delete;

};
