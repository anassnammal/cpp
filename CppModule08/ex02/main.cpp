#include "MutantStack.hpp"
#include <list>

int main() {
    // Test with MutantStack
    MutantStack<int> mutantStack;
    mutantStack.push(1);
    mutantStack.push(2);
    mutantStack.push(3);

    std::cout << "MutantStack:  ";
    for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test with std::list
    std::list<int> stdList;
    stdList.push_back(1);
    stdList.push_back(2);
    stdList.push_back(3);

    std::cout << "std::list:    ";
    for (std::list<int>::iterator it = stdList.begin(); it != stdList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

