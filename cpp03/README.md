1. Types of inheritance in C++:

- Public inheritance (public):

Public members of the base class remain public in the derived class.
Protected members of the base class continue to be protected in the derived class.

- Protected inheritance (protected):

The public and protected members of the base class become protected in the derived class

- Private inheritance (private):

Both public and protected members of the base class become private in the derived class.


2. Accessing members in a derived class:

- Public: Public members of the base class can be accessed directly from the derived class.

- Protected: Protected members of the base class can be accessed directly from the derived class, but not from outside the class or from objects in the base class.

- Private: Private members of the base class are not accessible from the derived class