#include <print>
#include <iostream>
#include <string>

int main() {
    // 1. Basic console I/O
    std::println("Hello {} World!", "This is from a print command.");
    std::cout << "This is from a cout." << std::endl;

    // 2. Vars and Types
    [[maybe_unused]] //removes the warning
    int a{ 42 }; // good to assign with an assignment list instead of just =
    [[maybe_unused]]
    int b{ a + 7 };
    [[maybe_unused]]
    float c{ 3.14f };
    [[maybe_unused]]
    double d { b * c };
    //(void)d; //void cast also removes 'unused' warning.
    
    char e { 'e' };
    
    std::string f("Adam");//constructor call for string, not ass'ment list
    
    bool g { true };

    e = 'b';

    // 3. constants
    constexpr int h { 14 }; // this can be evaluated at compile time so constexpr
    int userInput;
    std::cin >> userInput;
    const int i { h * userInput }; // this one can't be so we use a const
    std::cout << i << std::endl;

    // 4. control structures
    if(not g) {
        std::cout << "g was false!" << std::endl;
    } else if(f.starts_with(e)) {
        std::cout << "g was true and f starts with " << e << "." << std::endl;
    } else {
        std::cout << "something else happened." << std::endl;
    }

    // 5. loops
    
    for(int j{0}; j<10; j++) {
        //code
        std::cout << j << std::endl;
    }
}