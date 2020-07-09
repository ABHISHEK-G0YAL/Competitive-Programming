// https://www.hackerrank.com/challenges/cpp-variadics/problem
// Accepted


template<typename = void> int reversed_binary_value() {
    return 0;
}
template<bool bit, bool... bits> int reversed_binary_value() {
    return (reversed_binary_value<bits...>() << 1) + bit;
}

