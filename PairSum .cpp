// 1. Pair Sum (check if any two elements = target)
bool pairSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target)
                return true;
        }
    }
    return false;
}
