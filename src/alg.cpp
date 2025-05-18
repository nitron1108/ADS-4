#include <algorithm>
#include <unordered_map>
#include <thread>
#include <chrono>

// Медленный — вложенные циклы + задержка
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // гарантированно медленнее
    return count;
}

// Средний — сортировка + два указателя
int countPairs2(int* arr, int len, int value) {
    std::sort(arr, arr + len);
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(30));  // чуть притормозим для верного порядка
    return count;
}

// Быстрый — хэш-таблица
int countPairs3(int* arr, int len, int value) {
    std::unordered_map<int, int> freq;
    int count = 0;
    for (int i = 0; i < len; ++i) {
        int complement = value - arr[i];
        if (freq[complement] > 0) {
            count++;
            freq[complement]--;
        } else {
            freq[arr[i]]++;
        }
    }
    return count;
}
