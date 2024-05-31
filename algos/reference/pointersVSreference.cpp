#include <iostream>

int main() {
    int var = 42;
    int* ptr = &var;  // Pointer to var

    std::cout << "Value of var: " << var << std::endl;
    std::cout << "Address of var: " << &var << std::endl;
    std::cout << "Value of ptr: " << ptr << std::endl;
    std::cout << "Dereferenced ptr: " << *ptr << std::endl;

    int var2 = 100;
    ptr = &var2;  // Reassign pointer
    std::cout << "Reassigned ptr to var2: " << *ptr << std::endl;

    ptr = nullptr;  // Null pointer
    if (ptr == nullptr) {
        std::cout << "ptr is null" << std::endl;
    }

    return 0;
}
