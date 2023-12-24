#include <unordered_map>
#include <iostream>


template <
    typename KeyType, 
    typename ValueType, 
    typename Hash = std::hash<KeyType>, 
    typename KeyEqual = std::equal_to<KeyType>, 
    typename Allocator = std::allocator<std::pair<const KeyType, ValueType>>>
class AbstractDict {
public:
    void emplace(const KeyType& key, const ValueType& value) {
        dictionary.emplace(key, value);
    }

    void try_emplace(const KeyType& key, const ValueType& value) {
        dictionary.try_emplace(key, value);
    }

    ValueType get(const KeyType& key) const {
        return dictionary.at(key);
    }

    bool contains(const KeyType& key) const {
        return dictionary.contains(key);
    }

private:
    std::unordered_map<KeyType, ValueType, Hash, KeyEqual, Allocator> dictionary;
};