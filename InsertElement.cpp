/* Insert an Element in an Array

Problem: Write a C++ program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int pos;
    cin >> pos;
    int x;
    cin >> x;

    if (pos > n || pos <= 0)
    {
        cout << "INVALID POSITION" << endl;
        return 1;
    }

    int nums[n + 1];
    for (int i = 0; i < pos - 1; i++)
    {
        nums[i] = arr[i];
    }
    nums[pos - 1] = x;
    for (int i = pos - 1; i < n; i++)
    {
        nums[i + 1] = arr[i];
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
