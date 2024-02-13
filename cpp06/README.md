1. Types of Casts

- C-style cast: This is the most basic type of cast and also the least secure, it doesn't handle validation. Can convert between related and unrelated data types. May lead to unsafe conversions.

- Static_cast: This cast is safer than the C-style cast. It is used to perform conversions between related types at compile time (ckecks if compatible), handles validation. Also easier to search in code because of its syntax.

- Dynamic_cast: Used for casts between related classes at runtime in the context of inheritance. It can only be used with pointers or references to polymorphic classes (classes that have at least one virtual function). Its use is restricted primarily to inheritance situations. Easier to search in code.

- Reinterpret_cast: This cast performs unrestricted type conversions. It is very dangerous and should generally be avoided unless absolutely necessary.

- Const_cast: Add or remove const to something. Easier to search in code.


2. Dynamic_cast

- When dynamic_cast is used, the compiler checks whether the conversion between types is safe at runtime. If the conversion is possible and safe, dynamic_cast returns a pointer to the target type. If the conversion is not possible or not safe, dynamic_cast returns nullptr if it is a pointer or throws a std::bad_cast exception if it is a reference.