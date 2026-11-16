#include <bits/stdc++.h>
using namespace std;

// Items are {value, weight}; fractions of items may be taken.
double fractionalKnapsack(vector<pair<int, int>> items, int W) {
    sort(items.begin(), items.end(), [](auto &x, auto &y) {
        return (double)x.first / x.second > (double)y.first / y.second;
    });
    double total = 0;
    for (auto &it : items) {
        if (W == 0) break;
        if (it.second <= W) {
            total += it.first;
            W -= it.second;
        } else {
            total += (double)it.first * W / it.second;
            W = 0;
        }
    }
    return total;
}

int main() {
    vector<pair<int, int>> items = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;
    cout << "Maximum Value: " << fractionalKnapsack(items, capacity) << '\n';
    return 0;
}
