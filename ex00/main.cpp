#include <array> //non-resizable
#include <vector> //dynamic size
#include <deque> //pop and push from both sides
#include <list> //non-contiguous memory, like a linked list
#include <forward_list> //c++11, singly linked list

#include "easyfind.hpp"
#include <iostream>

int main(void) {

    std::array<int, 6> arr = {23, 45, 67, 28, 41, 77};

    // Vector initialization in C++98
    std::vector<int> vec;
    vec.push_back(755);
    vec.push_back(93);
    vec.push_back(4);
    vec.push_back(99);
    vec.push_back(23);
    vec.push_back(67);

    // Deque initialization in C++98
    std::deque<int> deq;
    deq.push_back(65);
    deq.push_back(9);
    deq.push_back(9876);
    deq.push_back(23);
    deq.push_back(0);

    // List initialization in C++98
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(32);
    lst.push_back(45);
    lst.push_back(2);

    try {
        int *result1 = easyfind(arr, 23);
        std::cout << "found in array: " << *result1 << std::endl;

        std::vector<int>::iterator result2 = easyfind(vec, 23);
        std::cout << "found in vector: " << *result2 << std::endl;
        
        std::cout << "found in deque: " << *(easyfind(deq, 23))<< std::endl;
        std::cout << "found in list: " << *(easyfind(lst, 23)) << std::endl;
    } catch (std::runtime_error const &e) {
        std::cout << e.what() << std::endl;
    }

    return (0);
}