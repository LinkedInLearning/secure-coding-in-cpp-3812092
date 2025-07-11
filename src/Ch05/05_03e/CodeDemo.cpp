// Secure Coding in C++
// Exercise 05_03
// Writing Secure Error Handling Code, by Eduardo Corpeño

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

void processInput(const std::string& input){
    if(input.empty())
        throw std::invalid_argument("Input cannot be empty.");
}

void loadFile(const std::string& filename){
    std::ifstream file(filename);
    if(!file)
        throw std::ios_base::failure("Failed to open file.");
}

int main(){
    try{
        processInput("");                 // Will throw
        loadFile("nonexistent.txt");      // Will throw
    }
    catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
        // Optional: rethrow or exit gracefully
    }

    std::cout << std::endl << std::endl;
    return 0;
}
