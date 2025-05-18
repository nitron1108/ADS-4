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
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    int pos = -1;

    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        pos = mid;
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    if (pos == -1)
      continue;

  
    int count_left = 1;
    int j = pos - 1;
    while (j > i && arr[j] == target) {
      count_left++;
      j--;
    }
    
    int count_right = 1;
    j = pos + 1;
    while (j < len && arr[j] == target) {
      count_right++;
      j++;
    }

    count += count_left + count_right - 1; // -1 потому что pos считается дважды
  }
  return count;
}
