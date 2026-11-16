#include <bits/stdc++.h>
using namespace std;

// 0/1 knapsack: each item can be selected at most once.
int knapsack01(vector<int> wt, vector<int> val, int W) {
    int n = wt.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i - 1][w];
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            }
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values = {1, 4, 5, 7};
    int capacity = 7;
    cout << "Maximum Value: " << knapsack01(weights, values, capacity) << '\n';
    return 0;
}
