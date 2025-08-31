#include <string>
#include <iostream>


import my_module;


int main() {
    std::string path;
    std::cin >> path;
    my_module::bulk_rename(path);
}