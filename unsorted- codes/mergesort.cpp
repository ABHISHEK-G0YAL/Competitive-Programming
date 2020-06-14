#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int input[], int start, int end) {
    int mid = (start + end) / 2;
    int i = start;
    int j = mid + 1;
    int k = start;
    int temp[end + 1];
    while(i <= mid and j <= end) {
        if(input[i] < input[j]) {
            temp[k] = input[i];
            k++;
            i++;
        } else {
            temp[k] = input[j];
            k++;
            j++;
        }
    }
    while(i <= mid) {
        temp[k] = input[i];
        k++;
        i++;
    }
    while(j <= end) {
        temp[k] = input[j];
        j++;
        k++;
    }
    for(int i = start; i <= end; i++)
        input[i] = temp[i];
}

void mergeSort(int input[], int start, int end) {
    if(start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(input, start, mid);
    mergeSort(input, mid + 1, end);
    merge(input, start, end);
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
}