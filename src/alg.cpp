// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count++;
            } else if (arr[i] + arr[j] > value) {
                break;
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
                count += (right - left + 1) * (right - left) / 2;
                break;
            }
            int temp_left = left;
            int temp_right = right;
            while (arr[temp_left] == arr[left]) temp_left++;
            while (arr[temp_right] == arr[right]) temp_right--;
            count += (temp_left - left) * (right - temp_right);
            left = temp_left;
            right = temp_right;
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
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                count++;
                int l = mid - 1;
                while (l >= left && arr[l] == target) {
                    count++;
                    l--;
                }
                int r = mid + 1;
                while (r <= right && arr[r] == target) {
                    count++;
                    r++;
                }
                break;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return count;
}
