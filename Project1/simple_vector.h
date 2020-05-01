#pragma once

#include <cstdlib>
#include <algorithm>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        my_vector_ = nullptr; capacity_ = size_ = 0;
    }
    explicit SimpleVector(size_t size) {
        capacity_ = size_ = size;
        my_vector_ = new T[size_];
    }
    ~SimpleVector() {
        delete[] my_vector_;
    }

    T& operator[](size_t index) { return my_vector_[index]; }

    T* begin() { return my_vector_; }
    T* end() { return my_vector_ + size_; }

    const T* begin() const { return my_vector_; }
    const T* end() const { return my_vector_ + size_; }

    size_t Size() const { return size_; }
    size_t Capacity() const { return capacity_; }
    void PushBack(const T& value) {
        if (my_vector_ == nullptr) {
            my_vector_ = new T[1];
            *my_vector_ = value;
            size_ = capacity_ = 1;
        }
        else if (size_ < capacity_)
            my_vector_[size_++] = value;
        else {
            capacity_ *= 2;
            T* tmp_vector = new T[capacity_];
            std::copy(my_vector_, my_vector_ + size_, tmp_vector);
            delete[] my_vector_;
            my_vector_ = tmp_vector;
            my_vector_[size_++] = value;
        }
    }

    void operator=(const SimpleVector& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        delete[] my_vector_;
        my_vector_ = new T[capacity_];
        std::copy(other.begin(), other.end(), begin());
    }

private:
    // Добавьте поля для хранения данных вектора
    T* my_vector_;
    size_t size_;
    size_t capacity_;
};
