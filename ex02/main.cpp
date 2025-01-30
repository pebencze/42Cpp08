#include <iostream>
#include "MutantStack.hpp"

int main(void) {
    MutantStack<int> mstack;

    std::cout << std::endl;
    std::cout << "Popping and pushing: " << std::endl;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Stack 5, 17. Top is: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Popped 17. New size: " << mstack.size() << std::endl;

    mstack.push(3); 
    mstack.push(5);
    mstack.push(8);
    mstack.push(9);
    std::cout << "Pushed 3, 5, 8 and 9. New size: " << mstack.size() << std::endl;

    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    
    std::cout << std::endl;
    std::cout << "Iterating: ";
    while (it != ite) {
        std::cout << *it << ", ";
        ++it; 
    }
    std::cout << std::endl;


    std::stack<int> s(mstack);
    std::stack<int> e;
    std::cout << "Copy constructed s. Size: " << s.size() << ". Is it empty? " << s.empty() << std::endl;
    std::cout << "Constructed e. Size: " << e.size() << ". Is it empty? " << e.empty() << std::endl;

    std::cout << std::endl;
    std::cout << "Different underlying container types: " << std::endl;
    std::stack<int, std::vector<int> > vector;
    vector.push(23);
    vector.push(11);
    std::cout << "Top of vector: " << vector.top() << std::endl;

    std::stack<int, std::list<int> > lst;
    lst.push(48);
    lst.push(92);
    lst.push(3987);
    std::cout << "Top of list: " << lst.top() << std::endl;

    std::stack<int, std::deque<int> > d;
    d.push(56);
    d.push(0);
    d.push(33);
    std::cout << "Top of deque: " << d.top() << std::endl;
    
    return 0;
}