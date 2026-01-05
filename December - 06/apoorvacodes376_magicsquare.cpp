#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        cout << "Magic square is only possible for odd values of n." << endl;
        return 0;
    }

    vector<vector<int>> square(n, vector<int>(n, 0));

    // Siamese method (de la Loubere)
    int num = 1;
    int r = 0, c = n / 2; // start at first row, middle column

    while (num <= n * n) {
        square[r][c] = num++;

        int nr = (r - 1 + n) % n; // move up (wrap)
        int nc = (c + 1) % n;     // move right (wrap)

        if (square[nr][nc] != 0) {
            r = (r + 1) % n;      // move down if cell occupied
            // c stays the same
        } else {
            r = nr;
            c = nc;
        }
    }

    // Print magic square
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << square[i][j] << (j + 1 == n ? "" : " ");
        }
        cout << "\n";
    }

    // Magic constant M = n(n^2 + 1)/2
    long long M = 1LL * n * (1LL * n * n + 1) / 2;
    cout << "Magic constant: " << M << endl;

    return 0;
}
