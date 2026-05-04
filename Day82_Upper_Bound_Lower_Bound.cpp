#include <bits/stdc++.h>
using namespace std;

int lowerBoundIndex(const vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int upperBoundIndex(const vector<int>& arr, int target) {
    int low = 0, high = arr.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= target) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 4, 6};
    cout << lowerBoundIndex(arr, 2) << ' ' << upperBoundIndex(arr, 2);
    return 0;
}
