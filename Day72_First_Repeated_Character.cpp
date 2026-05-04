#include <bits/stdc++.h>
using namespace std;

char firstRepeatedCharacter(const string& s) {
    vector<bool> seen(256, false);
    for (unsigned char ch : s) {
        if (seen[ch]) return ch;
        seen[ch] = true;
    }
    return '\0';
}

int main() {
    string s = "datastructures";
    char ans = firstRepeatedCharacter(s);
    cout << (ans ? string(1, ans) : "No repeated character");
    return 0;
}
