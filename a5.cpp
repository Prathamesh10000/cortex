#include <bits/stdc++.h>
using namespace std;

// Compute n choose k using Pascal's triangle (dynamic programming).
long long binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    vector<vector<long long>> C(n + 1, vector<long long>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) C[i][j] = 1;
            else C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main() {
    int n = 5, k = 2;
    cout << "Binomial Coefficient C(" << n << ", " << k << "): " << binomial(n, k) << '\n';
    return 0;
}
