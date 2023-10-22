#include <iostream>
using namespace std;


int count;

void merge(int arr[], int low, int mid, int high){
    int tmp[100];
    for(int i=low; i<=high; i++){
        tmp[i] = arr[i];
    }
    int idx1, idx2, merge_idx; // 양쪽에서 하나씩 머지위치에 추가해줌
    merge_idx = low; // 제일 왼쪽부터 시작
    idx1 = low;
    idx2 = mid+1;
    while(idx1<=mid && idx2<=high){ // 두 개 다 안끝나면 계속 함
        count++;
        if(tmp[idx1] <= tmp[idx2]) 
        {
            arr[merge_idx++] = tmp[idx1++];
        }
        else 
        {
            arr[merge_idx++] = tmp[idx2++];
        }
    }

    while(idx1 <= mid) arr[merge_idx++] = tmp[idx1++]; // 남은거 다 추가 해주기
    while(idx2 <= high) arr[merge_idx++] = tmp[idx2++];

}


void mergeSort(int arr[], int n){
    int size = 1; // 연속으로 merge할 데이터의 크기
    int low, mid, high;
    int end = n-1;
    while(size < n){
        for(int i=0; i<n; i+=2*size){
            low = i;            
            mid = min(i+size-1, end);
            high = min(i+2*size-1, end);
            merge(arr, low, mid, high);
        }
        size *= 2;
    }
}


int main(){
    int t;
    int arr[100];
    cin >> t; //테스트 케이스 개수 입력
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        for (int j=0; j<n; j++)
        {
            int num;
            count = 0;
            cin >> arr[j];
        }
    mergeSort(arr, n); 
        cout << count << '\n';

    }
	return 0;
}