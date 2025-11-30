/*Write a program using Bubble and Selection sort algorithm, assign the roll nos. to the students of your class as per their previous years result.
 i.e. topper will be roll no. 1 and analyse the sorting algorithm pass by pass.*/


#include <iostream>
using namespace std;

void print(int arr[], int n){
    for(int i = 0; i<n; i++){
        cout << "Array : " << arr[i] << " ";
        cout << endl;
    }
}

void selectionSort(int arr[], int n){
    cout << "\nSELECTION SORT (Pass by Pass):\n";
    for(int i = 0; i < n-1; i++){
        int maxidx = i;
        for(int j = i+1; j< n; j++){
            if(arr[j]> arr[maxidx]){
                maxidx = j;
            }
            swap(arr[i], arr[maxidx]);
        }
        cout << "Pass " << i + 1 << ": ";
        print(arr, n);
    }

    cout << "Final Roll Numbers:\n";
    for (int i = 0; i < n; i++)
        cout << "Roll " << i + 1 << ": " << arr[i] << endl;
}

void bubbleSort(int arr[], int n){
    cout << "\nBUBBLE SORT (Pass by Pass):\n";
    
    for(int i = 0; i<n-1; i++){
        for(int j = 0; j< n-1-i; j++){
            if(arr[j] < arr [j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
        cout << "Pass " << i + 1 << ": "<< endl;
        print(arr, n);
    }
    cout << "Final Roll Numbers:\n";
    for (int i = 0; i < n; i++)
        cout << "Roll " << i + 1 << ": " << arr[i] << endl;
    
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[100], b1[100], b2[100];

    cout << "Enter marks: ";
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
        b1[i] = marks[i];
        b2[i] = marks[i];
    }

    bubbleSort(b1, n);
    selectionSort(b2, n);

    return 0;
}