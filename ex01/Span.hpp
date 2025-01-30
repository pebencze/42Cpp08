#pragma once
#include <vector>

class Span {
    public: 
        Span(unsigned int N);
        Span(Span const &src);
        ~Span();

        Span & operator=(Span const &rhs);

        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

    private:
        std::vector<int>  _numbers;
        unsigned int      _maxSize;
        Span();
};