#pragma once
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T & container, int i) {
    typename T::iterator it = std::find(container.begin(), container.end(), i);

    if (it == container.end()) {
        throw std::runtime_error("Integer value not in container");
    }

    return (it);
}