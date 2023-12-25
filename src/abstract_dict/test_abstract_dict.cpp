#include <iostream>

#include "test_abstract_dict.h"
#include <string>


void test_abstract_dict() {
    std::cout << "##### test_abstract_dict ##### " << std::endl;

    AbstractDict<std::string> myStringDict;

    myStringDict.emplace("key1", 42);             // int value
    myStringDict.try_emplace("key2", 3.14);       // double value
    myStringDict.try_emplace("key3", "value");    // std::string value

    if (myStringDict.contains("key1")) {
        std::cout << "Value for key 'key1': " << myStringDict.get<int>("key1") << std::endl;
    }

    if (myStringDict.contains("key2")) {
        std::cout << "Value for key 'key2': " << myStringDict.get<double>("key2") << std::endl;
    }

    if (myStringDict.contains("key3")) {
        std::cout << "Value for key 'key3': " << myStringDict.get<std::string>("key3") << std::endl;
    }

    if (myStringDict.contains("four")) {
        std::cout << "Value for key 'four': " << myStringDict.get<int>("four") << std::endl;
    } else {
        std::cout << "Key 'four' not found." << std::endl;
    }

}
