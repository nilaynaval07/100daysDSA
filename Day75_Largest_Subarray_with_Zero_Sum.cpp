#include <bits/stdc++.h>
using namespace std;

int largestZeroSumSubarray(const vector<int>& arr) {
    unordered_map<int, int> firstIndex;
    int prefix = 0, best = 0;
    firstIndex[0] = -1;
    for (int i = 0; i < (int)arr.size(); i++) {
        prefix += arr[i];
        if (firstIndex.count(prefix)) best = max(best, i - firstIndex[prefix]);
        else firstIndex[prefix] = i;
    }
    return best;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23};
    cout << largestZeroSumSubarray(arr);
    return 0;
}
