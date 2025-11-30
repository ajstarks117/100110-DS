/*Write a program to arrange the list of employees as per the average of their height and weight by using Merge sorting method. Analyse their time complexities and conclude which 
algorithm will take less time to sort the list. */

#include <iostream>
#include <vector>
using namespace std;


struct employee{
    float height;
    float weight;
    float avg;  
};

void print(employee arr[], int n){
    for(int i = 0; i<n; i++){
        cout << "Employee " << i + 1 << ": Height = " << arr[i].height << ", Weight = " << arr[i].weight << ", Average = " << arr[i].avg << endl;
    }
}

void merge(employee arr[], int st, int mid, int end){
    vector<employee> temp;
    int i = st, j = mid +1;
    while(i <= mid && j<=end){
        if(arr[i].avg <= arr[j].avg){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while (j<=end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    
    // copy back to original array
    for(int k = 0; k < (int)temp.size(); ++k){
        arr[st + k] = temp[k];
    }
}

void mergeSort(employee arr[], int st, int end){
    if(st<end){
        int mid = st+(end-st)/2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid+1, end);

        merge(arr, st, mid, end);
    }
}

int main() {
    int n;
    cout << "Enter number of employees: ";
    cin >> n;

    employee e[100];

    cout << "Enter height and weight of each employee:\n";
    for (int i = 0; i < n; i++) {
        cin >> e[i].height >> e[i].weight;
        e[i].avg = (e[i].height + e[i].weight) / 2.0;
    }

    int pass = 0;
    mergeSort(e, 0, n - 1);

    cout << "Final Sorted List (Ascending by average):\n";
    print(e, n);

    return 0;
}
