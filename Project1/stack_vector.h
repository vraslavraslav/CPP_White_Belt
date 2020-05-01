#pragma once
#include <array>
#include <stdexcept>

using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) : vec_size(a_size), vec_capacity(N) {
        if (a_size > N)
            throw invalid_argument("Invalid StackVector size");
    }

    T& operator[](size_t index) { return vec[index]; }
    const T& operator[](size_t index) const { return vec.at(index); }

    auto begin() { return vec.begin(); }
    auto end() { return vec.begin() + vec_size; }
    auto const begin() const { return vec.cbegin(); }
    auto const end() const { return vec.cbegin() + vec_size; }

    size_t Size() const { return vec_size; }
    size_t Capacity() const { return vec_capacity; }

    void PushBack(const T& value) {
        if (vec_size == vec_capacity)
            throw overflow_error("NO space left for the new element");
        else
            vec[vec_size++] = value;
    }
    T PopBack() {
        if (vec_size == 0)
            throw underflow_error("StackVector is empty");
        else
            return vec[--vec_size];
    }

private:
    array<T, N> vec;
    size_t vec_size;
    size_t vec_capacity;
};

