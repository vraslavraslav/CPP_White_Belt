#pragma once
#include <cstdint>
#include <algorithm>

using namespace std;

// Реализуйте SimpleVector в этом файле
// и отправьте его на проверку

template <typename T>
class SimpleVector {
public:
    SimpleVector() = default;
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

    size_t Size() const { return size_; }
    size_t Capacity() const { return capacity_; }

    // При необходимости перегрузите
    // существующие публичные методы
    void PushBack(T value) {
        if (my_vector_ == nullptr) {
            my_vector_ = new T[1];
            my_vector_[0] = move(value);
            size_ = capacity_ = 1;
        }
        else if (size_ < capacity_)
            my_vector_[size_++] = move(value);
        else {
            capacity_ *= 2;
            T* tmp_vector = new T[capacity_];
            move(my_vector_, my_vector_ + size_, tmp_vector);
            delete[] my_vector_;
            my_vector_ = tmp_vector;
            my_vector_[size_++] = move(value);
        }
    }

private:
    // Добавьте сюда поля
    T* my_vector_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

};
