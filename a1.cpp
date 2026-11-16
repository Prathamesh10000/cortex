#include <bits/stdc++.h>
using namespace std;

// Iterative Fibonacci: steps count loop iterations.
long long fibIter(int n, int &steps) {
    steps = 0;
    if (n <= 1) return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        long long c = a + b;
        a = b;
        b = c;
        steps++;
    }
    return b;
}

// Recursive Fibonacci: steps count function calls.
long long fibRec(int n, long long &steps) {
    steps++;
    if (n <= 1) return n;
    return fibRec(n - 1, steps) + fibRec(n - 2, steps);
}

int main() {
    int n = 10;
    int iterativeSteps = 0;
    long long recursiveSteps = 0;
    cout << "Iterative Fibonacci: " << fibIter(n, iterativeSteps) << '\n';
    cout << "Iterative Steps: " << iterativeSteps << '\n';
    cout << "Recursive Fibonacci: " << fibRec(n, recursiveSteps) << '\n';
    cout << "Recursive Calls: " << recursiveSteps << '\n';
    return 0;
}
