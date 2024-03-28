#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    // Test case 1: Testing with vector
    std::vector<int> vec;
    vec.push_back(288);
    vec.push_back(548);
    vec.push_back(58);
    vec.push_back(88);
    vec.push_back(458);
    int target1 = 88;
    std::vector<int>::const_iterator result1 = easyfind(vec, target1);
    if (result1 != vec.end()) {
        std::cout << "Target " << target1 << " found in the vector" << std::endl;
    } else {
        std::cout << "Target " << target1 << " not found in the vector" << std::endl;
    }

    std::list<int> lst;
    lst.push_back(288);
    lst.push_back(548);
    lst.push_back(58);
    lst.push_back(88);
    lst.push_back(458);
    int target2 = 458;
    std::list<int>::const_iterator result2 = easyfind(lst, target2);
    if (result2 != lst.end()) {
        std::cout << "Target " << target2 << " found in the list" << std::endl;
    } else {
        std::cout << "Target " << target2 << " not found in the list" << std::endl;
    }

    int target3 = 5;
    std::list<int>::const_iterator result3 = easyfind(lst, target3);
    if (result3 != lst.end()) {
        std::cout << "Target " << target3 << " found in the list" << std::endl;
    } else {
        std::cout << "Target " << target3 << " not found in the list" << std::endl;
    }

    return 0;
}
