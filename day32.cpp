#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    const int MAX_SIZE = 100;
    int stack[MAX_SIZE];
    int top = -1;

    // Push n elements onto the stack
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (top < MAX_SIZE - 1)
        {
            stack[++top] = val;
        }
    }

    // Pop m elements
    int m;
    cin >> m;

    for (int i = 0; i < m && top >= 0; i++)
    {
        top--;
    }

    // Print remaining stack elements from top to bottom
    for (int i = top; i >= 0; i--)
    {
        cout << stack[i] << " ";
    }

    return 0;
}
