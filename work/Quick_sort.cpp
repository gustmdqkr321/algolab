#include <iostream>
using namespace std;

int hoare_count, hoare_Swap, lomuto_count, lomuto_Swap;

void swap(int* arr, int i, int j){  // 스왑
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}


int partition_hoare(int arr[], int low, int high){ 
    int pivot = arr[low]; // 제일 왼쪽을 피벗으로
    int i = low - 1;
    int j = high + 1;

    while(true)
    {
        hoare_count++; // 처음 비교 한번하고 while 진입
        while(arr[++i] < pivot) hoare_count++; // while 돌때마다 계속
        hoare_count++; // 
        while(arr[--j] > pivot) hoare_count++; //
        // 
        if(i < j) {
            hoare_Swap++; // swap
            swap(arr, i, j);
        }
        else return j; // i, j가 역전되면 종료해야함
    }
}

int partition_lomuto(int arr[], int low, int high){
    int pivot_index;

    int pivot = arr[low];
    int pivot_lower = low;

    for(int i=low+1; i<=high; i++)
    {
        lomuto_count++;     // 비교 연산
        if(arr[i] < pivot){
            pivot_lower++;
            lomuto_Swap++; // swap
            swap(arr, i, pivot_lower);
        }
    }
    pivot_index = pivot_lower;
    lomuto_Swap++; // swap
    swap(arr, low, pivot_index);    
    return pivot_index;
}

void quickSort_hoare(int arr[], int low, int high){
    int pivot_index;
    if(low < high){
        pivot_index = partition_hoare(arr, low, high);
        quickSort_hoare(arr, low, pivot_index);
        quickSort_hoare(arr, pivot_index+1, high);        
    }
}

void quickSort_lomuto(int arr[], int low, int high){
    int pivot_index;
    if(low < high){
        pivot_index = partition_lomuto(arr, low, high);
        quickSort_lomuto(arr, low, pivot_index-1);
        quickSort_lomuto(arr, pivot_index+1, high);
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        int input;
        cin >> n;
        
        int arr_hoare[n], arr_lomuto[n];
        hoare_count = 0;
        hoare_Swap = 0;
        lomuto_count = 0;
        lomuto_Swap = 0;

        for(int j=0; j<n; j++){
            cin >> input;
            arr_hoare[j] = input;
            arr_lomuto[j] = input;
        }
        quickSort_hoare(arr_hoare, 0, n-1);
        quickSort_lomuto(arr_lomuto, 0, n-1);
        cout << hoare_Swap << " " << lomuto_Swap << " " << hoare_count << " " << lomuto_count << '\n';

    }
    return 0;
}