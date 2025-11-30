/*Develop a program to identify and efficiently store a sparse matrix using compact representation and perform basic operations like display and simple transpose.*/

#include <iostream>
using namespace std;

#define MAX 100

void convertToSparse(int mtrx[10][10], int r, int c, int sparse[MAX][3]){
    int k = 1;
    for(int i = 0; i<r; i++){
        for(int j = 0; j< c; j++){
            if(mtrx[i][j] != 0){
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mtrx[i][j];
                k++;
            }
        }

        sparse[0][0] = r;
        sparse[0][1] = c;
        sparse[0][2] = k-1;
    }
}


void displaySparse(int sparse[MAX][3]){
    int n = sparse[0][2];
    cout << "No of non-zero elements: " << n << endl;
    cout << "Row\tCol\tValue\n";
    for(int i=0; i<=n;i++){
        cout << sparse[i][0]<< "\t" << sparse[i][1] << "\t" << sparse[i][2] << endl;
    }
}

void simpleTranspose(int sparse[MAX][3], int transposed[MAX][3]){
    int n = sparse[0][2];
    transposed[0][0] = sparse[0][1];
    transposed[0][1] = sparse[0][0];
    transposed[0][2] = n;
    int k = 1;
    for(int col = 0; col<sparse[0][1]; col++){
        for(int i = 1; i<=n;i++){
            if(sparse[i][1] == col){
                transposed[k][0] = sparse[i][1];
                transposed[k][1] = sparse[i][0];
                transposed[k][2] = sparse[i][2];
                k++;
            }
        }
    }
}

int main(){
    int mtrx[10][10], sparse[MAX][3];
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    cout << "Enter matrix elements:\n";
    for(int i = 0; i<r; i++){
        for(int j = 0; j< c; j++){
            cin >> mtrx[i][j];
        }
    }
    convertToSparse(mtrx, r, c, sparse);
    cout << "Sparse Matrix Representation:\n";
    displaySparse(sparse);
    return 0;
}