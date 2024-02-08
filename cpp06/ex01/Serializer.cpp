#include "Serializer.hpp"

//reinterpret_cast performs a raw cast between two types without considering their relationship.
//In the case of casting a pointer to uintptr_t, there is no direct relationship
//between a pointer and an unsigned integer, so reinterpret_cast is the most appropriate.

Serializer::Serializer() {}


Serializer::Serializer(const Serializer &source)
{
    *this = source;
}

Serializer &Serializer::operator=(const Serializer &source)
{
    (void)source;
    return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
