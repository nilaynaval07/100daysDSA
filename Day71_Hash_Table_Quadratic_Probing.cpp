#include <bits/stdc++.h>
using namespace std;

class HashTable {
    vector<int> table;
    vector<bool> used;

public:
    HashTable(int size) : table(size, -1), used(size, false) {}

    bool insert(int key) {
        int n = table.size();
        int h = key % n;
        for (int i = 0; i < n; i++) {
            int idx = (h + i * i) % n;
            if (!used[idx]) {
                table[idx] = key;
                used[idx] = true;
                return true;
            }
        }
        return false;
    }

    bool search(int key) {
        int n = table.size();
        int h = key % n;
        for (int i = 0; i < n; i++) {
            int idx = (h + i * i) % n;
            if (!used[idx]) return false;
            if (table[idx] == key) return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < (int)table.size(); i++) cout << i << ": " << (used[i] ? to_string(table[i]) : "-") << '\n';
    }
};

int main() {
    HashTable ht(11);
    for (int x : {21, 10, 32, 43, 54}) ht.insert(x);
    ht.print();
    cout << "Search 32: " << (ht.search(32) ? "Yes" : "No");
    return 0;
}
