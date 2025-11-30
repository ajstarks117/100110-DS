/*Write a program to input marks of n students Sort the marks in ascending order using the Quick Sort algorithm without using built-in library functions and analyse the sorting algorithm
pass by pass. Find the minimum and maximum marks using Divide and Conquer (recursively).*/

#include <iostream>
#include <vector>
using namespace std;

int partition(int arr[], int st, int end){
    int idx = st - 1;
    int pivot = arr[end];
    for(int j = st; j<end;j++){
        if(arr[j]<= pivot){
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(int arr[], int st, int end){
    if(st < end){
        int pi = partition(arr, st, end);
        quickSort(arr, st, pi-1);
        quickSort(arr, pi+1, end);
    }
}


void findMinMax(int arr[], int st, int end, int &minVal, int &maxVal)
{
    if (st == end)
    {
        minVal = maxVal = arr[st];
    }
    else if (end == st + 1)
    {
        if (arr[st] < arr[end])
        {
            minVal = arr[st];
            maxVal = arr[end];
        }
        else
        {
            minVal = arr[end];
            maxVal = arr[st];
        }
    }
    else
    {
        int mid = (st + end) / 2;
        int min1, max1, min2, max2;
        findMinMax(arr, st, mid, min1, max1);
        findMinMax(arr, mid + 1, end, min2, max2);
        minVal = min(min1, min2);
        maxVal = max(max1, max2);
    }
}
int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    vector<int> marks(n);
    cout << "Enter marks of students: ";
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }

    quickSort(marks.data(), 0, n - 1);

    cout << "Sorted marks: ";
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    int minVal, maxVal;
    findMinMax(marks.data(), 0, n - 1, minVal, maxVal);

    cout << "\nMin = " << minVal << "  Max = " << maxVal << endl;
    return 0;
}   