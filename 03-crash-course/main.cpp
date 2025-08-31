#include <exception>
#include <fstream>
#include <memory>
#include <optional>
#include <print>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

// see section 6 of main()
auto multiply(int a, double b) {
    return a*b;
}

// see section 8 of main()
std::optional<int> returnBigOdd(int a) {
    if(a%2 == 1 && a > 1000)
        return a;
    else
        return std::nullopt;
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

    // 8. optionals - bit like a maybe in haskell
    auto numOptional = returnBigOdd(198765);
    if(numOptional.has_value()) {
        std::println("The number {} is big and odd.", numOptional.value());
    }


    // 9. references

    int omega {7};
    int& omegaRef {omega};
    omegaRef = 8;
    std::println("Value of omega: {}", omega);
    std::println("Value of omegaRef: {}", omegaRef);

    // 10. raw pointers and smart pointers
    int* raw_ptr{&omega}; // rarely needed; should never hold ownership of data
    std::println("Value of omega: {}", *raw_ptr);
    //std::println("Value of the pointer: {}", ptr); //this doesn't compile
    //doesn't clean up after itself

    std::unique_ptr<int> smartPtr{ std::make_unique<int>(10) }; //use this if need to use pointers
    std::println("Value of the smart pointer: {}", *smartPtr);
    //cleans up after itself once out of scope


    // 10. classes/structs and objects
    class House {
        protected:
            int price;
            int height;
            int numOfDoors;
        public:
            House(int price, int height, int numOfDoors)
                :price{price}, height{height}, numOfDoors{numOfDoors}
            {
                std::println("Another great house built by AmazeBuild!");
            }

            virtual void printInfo() const {
                std::println("Price: {}\nHeight: {}\nDoors: {}", price, height, numOfDoors);
            }
    };

    House myHome(10000,10,2);
    myHome.printInfo();

    // 11. inheritance
    class SpecialHouse : public House {
        public:
            SpecialHouse(int mult) : House(300000*mult, 10*mult, 10*mult) {
                std::println("This one is a speshul house!");
            }

            void jump(int jumpHt) {
                std::println("The house jumped {}m in the air!", jumpHt);
            }
            void valInc(int amount) {
                price += amount;
            }
            void printInfo() const override {
                std::println("Price: ${}\nHeight: {}m\nDouble-Doors: {}", price, height, numOfDoors);
            }
    };

    SpecialHouse superHome(100);
    superHome.printInfo();
    superHome.jump(10);
    superHome.valInc(1000000);
    superHome.printInfo();

    //the overridden func on line 169 means we can do the following:
    House* housePtr;
    if(not g)
        housePtr = &myHome;
    else
        housePtr = &superHome;
    std::println("The pointer-derived info:");
    housePtr->printInfo();


    //12. Standard Template Library algorithms
    std::vector<int> anotherVector{ 3,1,4,1,5,9,2,6,5,4 };
    std::sort(anotherVector.begin(),anotherVector.end());

    for(int num : anotherVector) {
        std::print("{} ", num);
    }
    std::println("Vector got sorted!");

    //13. try and catch
    try {
        // do some stuff
        if(true) {
            throw std::runtime_error("useful message about the exception.");
        }
        std::println("This will not get printed because an error got thrown.");
    } catch (const std::exception& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Something bad happened, don't know what.";
    }

    //14. auto
    [[maybe_unused]]
    auto test1 = 7;
    [[maybe_unused]]
    auto test2 = "Do what I mean";
    auto test3 = std::string("Do what I mean");
    const auto& test4 = std::string("This won't change.");

    //15. file i/o
    std::ofstream file("example.txt");
    file << "Line 1" << std::endl;
    file << "Line 2" << std::endl;
    file.close();

    std::ifstream inputFile("example.txt");
    std::string line;
    while(std::getline(inputFile,line)) {
        std::println("[READ]: {}", line);
    }

}