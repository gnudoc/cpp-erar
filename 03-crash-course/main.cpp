#include <print>
#include <iostream>
#include <string>
#include <vector>

// see section 6 of main()
auto multiply(int a, double b) {
    return a*b;
}

int main() {
    // 1. Basic console I/O
    std::println("Hello {} World!", "This is from a print command.");
    std::cout << "This is from a cout." << std::endl;

    // 2. Vars and Types
    
    int a{ 42 }; // good to assign with an assignment list instead of just =
    
    int b{ a + 7 };
    
    float c{ 3.14f };
    
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

    //also case-switch

    // 5. loops
    
    for(int j{0}; j<10; j++) {
        //code
        std::cout << j << std::endl;
    }

    while(g) {
        std::cout << "loopy" << std::endl;
        b++;
        if (b>55) {
            g = false;
        }
    }

    //also do-while

    // 6. functions
    // see the top of the file for this one
    double result = multiply(a,d);
    std::cout << result << std::endl;

    //this one is a lambda
    auto add = [](int x, int y) -> int {
        return x + y;
    };
    int res = add(7,21);
    std::println("Res of lambda is {}.", res);//note can't just println an int


    // 7. arrays & vectors
    int numArray[5] {1, 2, 3, 4, 5}; //old arrays
    numArray[2] = 200; // possible out-of-bounds array usage
    
    std::array<int,5> modernArray {1,2,3,4,5}; //new & fancy
    modernArray[2] = 500; // possible out-of-bounds array usage
    modernArray.at(2) = 700; //does a bounds check

    std::vector<int> numVector {1,2,3,4,5};
    numVector.push_back(6); // vectors can grow dynamically!

    for(auto elem : numVector) { // can do w modern arrays too
        std::print("{} ", elem);
    }
    std::println("\nEnd!");

    // 8. optionals
}