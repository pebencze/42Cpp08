#pragma once
#include <stack>
#include <deque>
#include <vector>
#include <list>
#include <iterator>

template < class T = int, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
    public: 
        MutantStack() : std::stack<T, Container>(){};
        ~MutantStack() {};
        MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};

        MutantStack &operator=(const MutantStack& rhs) {
            if (this != &rhs) {
                std::stack<T, Container>::operator=(rhs);
            }
        };

        typedef typename Container::iterator iterator;

        iterator begin() {return this->c.begin();};
        iterator end() {return this->c.end();};
};