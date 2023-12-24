#include <iostream>

#include "test_abstract_dict.h"
#include <string>


void test_abstract_dict() {

    AbstractDict<std::string, int> myStringIntDict;
    myStringIntDict.try_emplace("one", 1);
    myStringIntDict.try_emplace("two", 22);
    std::cout << "Value for key 'two': " << myStringIntDict.get("two") << std::endl;
    if (myStringIntDict.contains("four")) {
        std::cout << "Value for key 'four': " << myStringIntDict.get("four") << std::endl;
    } else {
        std::cout << "Key 'four' not found." << std::endl;
    }
    
}
