#pragma once

template <typename First, typename Second>
class Pair {
public:
    First first;
    Second second;

    Pair(First first_, Second second_) : first(first_), second(second_) {}

    Pair operator+(const Pair &other) const {
        return Pair(first + other.first, second + other.second);
    }

    bool operator>(const Pair &other) const {
        return (first + second) > (other.first + other.second);
    }
};
