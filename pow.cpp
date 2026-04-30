/* Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32 */

#include <iostream>
using namespace std;

int power(int n, int k)
{

    if (k == 0)
        return 1;

    return 2 * power(n, k - 1);
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;

    cout << power(n, k) << endl;
}
