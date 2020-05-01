#pragma once

bool IsPalindrom(const string& str) {
    auto size = str.size();
    if (size == 0 || size == 1)
        return true;
    for (int i = 0; i < size / 2; ++i)
        if (str[i] != str[size - i - 1])
            return false;
    return true;
}