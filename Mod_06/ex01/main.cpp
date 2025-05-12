#include "Serializer.hpp"

int main() 
{
    Data data;
    data.value = 42;

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Original value: " << data.value << std::endl;
    std::cout << "Deserialized value: " << ptr->value << std::endl;

    if (&data == ptr) 
        std::cout << "\nPointer deserialization successful. Have a wonderful day.\n"; 
    else 
        std::cout << "\nDeserialization failed!\n\nToday has been a total waste. Go home, drink a glass of wine, go to bed.\n";
    
    
    return 0;
}

