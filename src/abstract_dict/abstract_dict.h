#include <iostream>
#include <variant>
#include <unordered_map>


template <
    typename KeyType,
    typename Hash = std::hash<KeyType>,
    typename KeyEqual = std::equal_to<KeyType>,
    typename Allocator = std::allocator<std::pair<const KeyType, std::variant<int, double, std::string>>>
>
class AbstractDict {
public:
    template <typename U>
    void emplace(const KeyType& key, const U& value) {
        dictionary.emplace(key, value);
    }

    template <typename U>
    void try_emplace(const KeyType& key, const U& value) {
        dictionary.try_emplace(key, value);
    }

    template <typename U>
    U get(const KeyType& key) const {
        return std::get<U>(dictionary.at(key));
    }

    bool contains(const KeyType& key) const {
        return dictionary.contains(key);
    }

private:
    std::unordered_map<KeyType, std::variant<int, double, std::string>, Hash, KeyEqual, Allocator> dictionary;
};