// Copyright 2021 NNTU-CS

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
      while (left + left_count < right && arr[left] == arr[left + left_count]) {
        left_count++;
      }

      int right_count = 1;
      while (right - right_count > left && arr[right] == arr[right - right_count]) {
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
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;

    // бинарный поиск всех вхождений target, считаем количество повторов
    int first_occurrence = -1;
    int last_occurrence = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        first_occurrence = mid;
        right = mid - 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (first_occurrence == -1) continue;

    // найти последнее вхождение target
    left = first_occurrence;
    right = len - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        last_occurrence = mid;
        left = mid + 1;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    int count_targets = last_occurrence - first_occurrence + 1;
    count += count_targets;
  }
  return count;
}
