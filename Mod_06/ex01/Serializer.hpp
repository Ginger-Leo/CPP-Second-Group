#pragma once
#include <iostream>
#include <cstdint>

struct Data
{
    int value;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer&) = delete;
        Serializer& operator=(const Serializer&) = delete;
    
    protected:
    
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};
