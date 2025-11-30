/*Write a program to construct and verify a magic square of order 'n' (for both even & odd) such that all rows, columns, and diagonals sum to the same value.*/

#include <iostream>
using namespace std;

int square[50][50];  


void generateOdd(int n) {
    int i = 0, j = n/2;

    for (int num = 1; num <= n*n; num++) {
        square[i][j] = num;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;

        if (square[newi][newj] != 0)
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }
}


void generateDoublyEven(int n) {
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = num++;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if ((i % 4 == j % 4) || ((i + j) % 4 == 3))
                square[i][j] = (n*n + 1) - square[i][j];
}


void generateSinglyEven(int n) {
    int half = n / 2;
    int sub = half * half;

    int temp[25][25] = {0};


    int a = 0, b = half / 2;
    for (int num = 1; num <= sub; num++) {
        temp[a][b] = num;
        int na = (a - 1 + half) % half;
        int nb = (b + 1) % half;

        if (temp[na][nb] != 0)
            a = (a + 1) % half;
        else {
            a = na;
            b = nb;
        }
    }


    for (int i = 0; i < half; i++)
        for (int j = 0; j < half; j++) {
            square[i][j] = temp[i][j];
            square[i][j + half] = temp[i][j] + 2 * sub;
            square[i + half][j] = temp[i][j] + 3 * sub;
            square[i + half][j + half] = temp[i][j] + sub;
        }

    int k = (n - 2) / 4;


    for (int i = 0; i < half; i++)
        for (int j = 0; j < k; j++)
            swap(square[i][j], square[i + half][j]);

    for (int i = 0; i < half; i++)
        for (int j = n - k + 1; j < n; j++)
            swap(square[i][j], square[i + half][j]);
}


bool verify(int n) {
    int magicSum = n * (n*n + 1) / 2;

    for (int i = 0; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) rowSum += square[i][j];
        if (rowSum != magicSum) return false;
    }

   
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) colSum += square[i][j];
        if (colSum != magicSum) return false;
    }

    int d1 = 0, d2 = 0;
    for (int i = 0; i < n; i++) {
        d1 += square[i][i];
        d2 += square[i][n - 1 - i];
    }
    return (d1 == magicSum && d2 == magicSum);
}


int main() {
    int n;
    cout << "Enter order n of Magic Square: ";
    cin >> n;

    if (n < 3) {
        cout << "Magic square not possible for n < 3\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = 0;

 
    if (n % 2 == 1)
        generateOdd(n);
    else if (n % 4 == 0)
        generateDoublyEven(n);
    else
        generateSinglyEven(n);

    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << square[i][j] << "\t";
        cout << endl;
    }


    if (verify(n))
        cout << "\n✔ This IS a Magic Square.\n";
    else
        cout << "\n❌ This is NOT a Magic Square.\n";

    return 0;
}
