#include <bits/stdc++.h>
using namespace std;

char firstNonRepeatingCharacter(const string& s) {
    vector<int> freq(256, 0);
    for (unsigned char ch : s) freq[ch]++;
    for (unsigned char ch : s) {
        if (freq[ch] == 1) return ch;
    }
    return '\0';
}

int main() {
    string s = "swiss";
    char ans = firstNonRepeatingCharacter(s);
    cout << (ans ? string(1, ans) : "No non-repeating character");
    return 0;
}
