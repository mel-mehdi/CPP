#include "Serializer.hpp"
int main()
{
    Data data;
    data.value = 42;
    data.character = 'X';
    data.decimal = 3.14;
    
    std::cout << "Original address: " << &data << std::endl;
    std::cout << "Original values: " << data.value << ", " << data.character << ", " << data.decimal << std::endl;
    
    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);
    
    std::cout << "After serialization: " << raw << std::endl;
    std::cout << "Deserialized address: " << ptr << std::endl;
    std::cout << "Deserialized values: " << ptr->value << ", " << ptr->character << ", " << ptr->decimal << std::endl;
    
    std::cout << "Pointers match: " << (ptr == &data ? "YES" : "NO") << std::endl;
    
    return 0;
}