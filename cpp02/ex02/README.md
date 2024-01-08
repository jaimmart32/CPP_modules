1. DIFFERENCE BETWEEN ++A AND A++ OPERATOR OVERLOAD FUNCTION

The function prototype can be the same for both so ++A will have void as parameter and A++ int or whatever type so that the compiler can differentiate them

Also, in the A++ operator overload function we need an aux variable so than we can sotre the old value and return it after the increment. We CANT return a reference to that variable because is a local variable that only will exist in the scope of the operator overload function, a reference cant admit that behavior for security reasons so we will have to return the aux variable itself so that it survives after the scope of the function. We could also use dinamic memory to avoid undefined behavior but i chosed to return the value itself.

2. MEMBER FUNCTIONS "STATIC"

It means it is a function that belongs to the class itsealf and not to an instance of the class.

- They dont have access to non static members of the class.

- You can call these functions without creating an instance, directly using the name of the class.

- They dont have a "this" pointer.
