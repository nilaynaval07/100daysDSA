/* Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left */

#include <iostream>
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
    if (pos > n || pos < 0)
    {
        cout << "Invalid Position" << endl;
        return 1;
    }

    int UpdatedArr[n - 1] = {0};
    for (int i = 0; i < pos - 1; i++)
    {
        UpdatedArr[i] = arr[i];
    }
    for (int i = pos; i < n; i++)
    {
        UpdatedArr[i - 1] = arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << UpdatedArr[i] << " ";
    }
}