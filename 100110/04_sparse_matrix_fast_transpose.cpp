#include <iostream>
using namespace std;

struct Term {
    int r, c, v;   // row, col, value
};

int main() {
    int m, n, nz;
    Term S[50], T[50];
    int total[50] = {0};
    int index[50];

    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> m >> n >> nz;

    // Header of original sparse matrix
    S[0].r = m;
    S[0].c = n;
    S[0].v = nz;

    cout << "Enter the triplets (row col value):\n";
    for (int i = 1; i <= nz; i++) {
        cin >> S[i].r >> S[i].c >> S[i].v;
    }

    // Step 1: set header for transpose
    T[0].r = S[0].c;   // rows <-> cols
    T[0].c = S[0].r;
    T[0].v = S[0].v;

    // Step 2: count number of elements in each column of S
    for (int i = 1; i <= nz; i++) {
        total[ S[i].c ]++;   // column number as index
    }

    // Step 3: compute starting indices for each column in T
    index[0] = 1;            // first non-zero goes at position 1
    for (int col = 1; col < n; col++) {
        index[col] = index[col - 1] + total[col - 1];
    }

    // Step 4: place terms directly into correct position
    for (int i = 1; i <= nz; i++) {
        int col = S[i].c;
        int pos = index[col];     // where this element will go in T

        T[pos].r = S[i].c;        // swapped
        T[pos].c = S[i].r;
        T[pos].v = S[i].v;

        index[col]++;             // next element of this column will go to next position
    }

    // Display original
    cout << "\nOriginal Sparse Matrix (Triplet Form):\n";
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i <= nz; i++) {
        cout << S[i].r << "\t" << S[i].c << "\t" << S[i].v << endl;
    }

    // Display transpose
    cout << "\nFast Transpose (Triplet Form):\n";
    cout << "Row\tCol\tVal\n";
    for (int i = 0; i <= nz; i++) {
        cout << T[i].r << "\t" << T[i].c << "\t" << T[i].v << endl;
    }

    return 0;
}
