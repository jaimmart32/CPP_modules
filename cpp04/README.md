1. SHALLOW COPY VS DEEP COPY

- Performing a shallow copy means that the pointer value is copied, but not the content itself; This means that both objects (the copy and the original) would be sharing a single object (they would both be pointing to the same object), and at some point (on destruction) both objects would try to delete the same block of memory, probably causing the program to crash on runtime. This can be solved by defining the following custom copy constructor that performs a deep copy.

- The deep copy performed by a copy constructor allocates storage for a new object, which is initialized to contain a copy of the original object. In this way, both objects (copy and original) have distinct copies of the content stored in different locations.

2. ABSTRACT METHODS

- Every class that inherits an abstract method is forced by a "contract" to declare and implement it, otherwise the compiler will print an error. Each derived class must provide its own implementation for all abstract member functions of the base class.

3. VIRTUAL

- If a pointer of type base class points to an object of a derived class and is destroyed with delete the pointer, thanks to the fact that the destructor is virtual it will know that it has to call the destructor of the derived class and not that of the base class.

- The same thing happens when there is a pointer of type base class and an object of type derived class is assigned to it and there is a virtual method, if the method is called through this pointer, thanks to virtual it will know that it has to call the method of the derived class and not that of the base class.

This is the reason why the keyword "virtual" is o important when working with polymorfism and pointers of a base class type that point to derived classes objects.