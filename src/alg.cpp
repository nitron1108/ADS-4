// Copyright 2021 NNTU-CS
#include <unordered_map>

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        int n = right - left + 1;
        count += n * (n - 1) / 2;
        break;
      }

      int left_count = 1;
      while (left + left_count < right &&
             arr[left] == arr[left + left_count]) {
        left_count++;
      }

      int right_count = 1;
      while (right - right_count > left &&
             arr[right] == arr[right - right_count]) {
        right_count++;
      }

      count += left_count * right_count;
      left += left_count;
      right -= right_count;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  std::unordered_map<int, int> freq;
  for (int i = 0; i < len; ++i) {
    freq[arr[i]]++;
  }

  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    if (freq.find(target) != freq.end()) {
      count += freq[target];
    }

    if (arr[i] * 2 == value) {
      count--;
    }
  }

  return count / 2;
}
