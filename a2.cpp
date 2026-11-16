#include <bits/stdc++.h>
using namespace std;
//g++ a2.cpp -o a1 && ./a2
// Jobs are {deadline, profit}; each takes one time slot.
int jobSequencing(vector<pair<int, int>> jobs) {
    sort(jobs.begin(), jobs.end(), [](auto &x, auto &y) {
        return x.second > y.second;
    });
    int maxD = 0;
    for (auto &j : jobs) maxD = max(maxD, j.first);
    vector<bool> used(maxD + 1, false);
    int profit = 0;
    for (auto &j : jobs) {
        for (int s = j.first; s >= 1; s--) {
            if (!used[s]) {
                used[s] = true;
                profit += j.second;
                break;
            }
        }
    }
    return profit;
}

int main() {
    vector<pair<int, int>> jobs = {{2, 100}, {1, 19}, {2, 27}, {1, 25}, {3, 15}};
    cout << "Maximum Profit: " << jobSequencing(jobs) << '\n';
    return 0;
}
