#include "Span.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>

Span::Span() : _maxSize(0) {

}

Span::Span(unsigned int N) : _maxSize(N) {

}

Span::Span(Span const &src) : _numbers(src._numbers), _maxSize(src._maxSize) {

}

Span::~Span() {

}

Span & Span::operator=(Span const &rhs) {
    if (this != &rhs) {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_numbers.size() == _maxSize)
        throw std::runtime_error("Vector is full.");
    _numbers.push_back(n);
}

int Span::shortestSpan() const {
    std::vector<int> sortedCopy;
    sortedCopy = _numbers;
    std::sort(sortedCopy.begin(), sortedCopy.end());
    int span;
    int minSpan;
    if (sortedCopy.size() <= 1)
        throw std::runtime_error("Vector is too small or empty.");
    minSpan = sortedCopy[1] - sortedCopy[0];
    for (size_t i = 2; i < sortedCopy.size(); i++) {
        span = sortedCopy[i] - sortedCopy[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    std::vector<int> sortedCopy;

    sortedCopy = _numbers;
    std::sort(sortedCopy.begin(), sortedCopy.end());
    return static_cast<unsigned int>((sortedCopy[sortedCopy.size() - 1] - sortedCopy[0]));
}

void Span::addMany(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t amount = std::distance(begin, end);
    if (amount > _maxSize - _numbers.size())
        throw std::logic_error("Iterator range is too big.");
    while (begin != end) {
        addNumber(*begin);
        begin++;
    }
}

void Span::printSpan() {
    std::vector<int>::iterator it;

    for (it = _numbers.begin(); it != _numbers.end(); it++) {
        std::cout << *it << ", ";
    }
}