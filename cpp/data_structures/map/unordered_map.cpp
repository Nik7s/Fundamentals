#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> myMap;

    // Insert key-value pairs
    myMap["One"] = 1;
    myMap["Two"] = 2;
    myMap["Three"] = 3;

    // Access values
    std::cout << "Value for key 'Two': " << myMap["Two"] << std::endl;

    // Check if a key exists
    if (myMap.find("Four") != myMap.end()) {
        std::cout << "Value for key 'Four': " << myMap["Four"] << std::endl;
    } else {
        std::cout << "Key 'Four' not found." << std::endl;
    }

    return 0;
}
