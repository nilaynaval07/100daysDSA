#include <bits/stdc++.h>
using namespace std;

string electionWinner(const vector<string>& votes) {
    map<string, int> count;
    for (const string& name : votes) count[name]++;
    string winner;
    int best = -1;
    for (map<string, int>::iterator it = count.begin(); it != count.end(); ++it) {
        string name = it->first;
        int votesCount = it->second;
        if (votesCount > best) {
            best = votesCount;
            winner = name;
        }
    }
    return winner;
}

int main() {
    vector<string> votes = {"alice", "bob", "alice", "carol", "bob", "alice"};
    cout << electionWinner(votes);
    return 0;
}
