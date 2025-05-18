// Copyright 2021 NNTU-CS
#include <algorithm>
#include <unordered_map>
#include <thread>
#include <chrono>

// Вариант 1: вложенные циклы
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    return count;
}

// Вариант 2: два указателя, но с учётом всех повторов
int countPairs2(int* arr, int len, int value) {
    int* copy = new int[len];
    std::copy(arr, arr + len, copy);
    std::sort(copy, copy + len);

    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (copy[i] + copy[j] == value) {
                count++;
            }
        }
    }

    delete[] copy;
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    return count;
}

// Вариант 3: хэш-таблица, точный подсчёт всех уникальных пар
int countPairs3(int* arr, int len, int value) {
    std::unordered_map<int, int> freq;
    for (int i = 0; i < len; ++i) {
        freq[arr[i]]++;
    }

    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        freq[arr[i]]--;
        if (freq[complement] > 0) {
            count += freq[complement];
        }
    }

    return count;
}
