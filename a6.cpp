#include <bits/stdc++.h>
using namespace std;

// q[r] = column of queen in row r; -1 indicates an empty row.
bool isSafe(vector<int> &q, int r, int c) {
    for (int i = 0; i < 8; i++) {
        // A queen cannot share a column or diagonal with another queen.
        if (q[i] != -1 && (q[i] == c || abs(q[i] - c) == abs(i - r)))
            return false;
    }
    return true;
}

bool placeQueens(vector<int> &q, int r) {
    if (r == 8) return true;
    if (q[r] != -1) return placeQueens(q, r + 1); // Fixed queen's row.
    for (int c = 0; c < 8; c++) {
        if (isSafe(q, r, c)) {
            q[r] = c;
            if (placeQueens(q, r + 1)) return true;
            q[r] = -1; // Backtrack.
        }
    }
    return false;
}

vector<int> eightQueens(int row, int col) {
    vector<int> q(8, -1);
    q[row] = col;
    if (placeQueens(q, 0)) return q;
    return {};
}

int main() {
    int row = 0, col = 0;
    vector<int> q = eightQueens(row, col);
    if (q.empty()) {
        cout << "No solution exists\n";
    } else {
        cout << "8-Queens Solution:\n";
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                cout << (q[r] == c ? "Q " : ". ");
            }
            cout << '\n';
        }
    }
    return 0;
}
