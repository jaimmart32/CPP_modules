1. TEMPLATED CONTAINERS

- Templated containers are classes that store collections of elements.

- Containers provide different ways to access, insert, and delete elements.

- Each type of container has its own features and advantages, for example, vector provides fast access to elements but can be expensive in terms of insertion and deletion in certain scenarios, while list offers fast insertion and deletion but can be less efficient in random access .


    · ASSOCIATIVE CONTAINERS
        - They store elements ordered according to a specific criterion, usually a key associated with each element. This means that items are organized and stored based on a value that is used to quickly access them, rather than their position in the container(std::set, std::map, std::multiset, std::multimap...).

    · SEQUENCE CONTAINERS
        - They store and organize elements in an ordered sequence. Elements in a sequence container are stored contiguously in memory and are accessed based on their relative position in the sequence(std::vector, std::list, std::deque, std::forward_list).

    · ADAPTER CONTAINERS
        - They provide specific interfaces for certain operations (for example, LIFO or FIFO). Although some adapter containers may not support iterators directly, they may internally be backed by sequence containers and can therefore be accessed indirectly through the iterators of the underlying containers.


2. ITERATORS

- They are objects that act as pointers, allowing sequential navigation through the elements stored in a container.

- They provide operations like dereferencing, increment, decrement, etc.

- Common types of iterator include:
    · iterator
    · const_iterator
    · reverse_iterator
    · const_reverse_iterator

- Iterators allow STL algorithms to work with different types of containers in a generic way, without needing to know the specific implementation of the container.

- While pointers are more primitive and tied more to direct memory manipulation, iterators provide a safer, more generalized abstraction for traversing and accessing container elements.


3. STL ALGORITHMS

- They are defined in the STL and provide a wide range of functionality for manipulating and processing containers and their elements.

- They cover a wide variety of tasks, such as search, sorting, manipulation, transformation, comparison, among others.