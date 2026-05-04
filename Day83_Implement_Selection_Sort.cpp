#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    for (int i = 0; i < (int)arr.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < (int)arr.size(); j++) {
            if (arr[j] < arr[minIndex]) minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    for (int x : arr) cout << x << ' ';
    return 0;
}
