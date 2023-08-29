# doublelinklist
This is a double linked list data structure that is developed using a regular C++ pointers, struct and class.
The class have a constructor and destructor which enables to return the memory that is aquired using new operator to the OS.
The class also have a various methods to add, search, delete and display the double linked list contents. 
The class also overload the index ([]) operator to access the elements of the double linked list in random access manner. However,
this operation is too slow as the size of of the double linked list increases. 
The double linked list class is fully templized to make it generic so that it can work with any kinds of data types icluding user defined objects.
