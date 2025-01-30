#include "Span.hpp"
#include <iostream>

int main() {
  std::cout << std::endl;
  try {
    std::cout << "\e[0;31mtesting all functions: " << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    std::cout << "\e[0;33mtesting vector of size 1: " << std::endl;
    Span smallSp = Span(1);
    smallSp.addNumber(8);
    std::cout << smallSp.shortestSpan() << std::endl;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    std::cout << "\e[0;34mtesting empty vector: " << std::endl;
    Span emptySp = Span(0);
    emptySp.addNumber(12);
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << std::endl;
  try {
    std::cout << "\e[0;35mtesting vector of size 10.000: " << std::endl;
    Span bigSp = Span(10000);
    for (unsigned int i = 0; i < 10000; i++) {
      bigSp.addNumber(i);
    }
    std::cout << bigSp.longestSpan() << std::endl;
    std::cout << bigSp.shortestSpan() << std::endl;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\e[0m" << std::endl;
return 0; 
}