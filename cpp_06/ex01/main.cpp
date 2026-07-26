#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
    Data data;

    data.name = "Zakaria";
    data.age = 21;

    std::cout << "Original object:" << std::endl;
    std::cout << "Address : " << &data << std::endl;
    std::cout << "Name    : " << data.name << std::endl;
    std::cout << "Age     : " << data.age << std::endl;

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "\nSerialized value: " << raw << std::endl;

    Data *ptr = Serializer::deserialize(raw);

    std::cout << "\nDeserialized object:" << std::endl;
    std::cout << "Address : " << ptr << std::endl;
    std::cout << "Name    : " << ptr->name << std::endl;
    std::cout << "Age     : " << ptr->age << std::endl;

    if (ptr == &data)
        std::cout << "\nSUCCESS: Pointers are identical." << std::endl;
    else
        std::cout << "\nERROR: Pointers are different." << std::endl;

    return 0;
}