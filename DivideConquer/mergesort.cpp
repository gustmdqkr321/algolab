#include <iostream>
using namespace std;


int count;

void merge(int arr[], int left, int mid, int right){
    int tmp[100];

    for(int i=left; i<=right; i++) // 원본 배열 저장
    {
        tmp[i] = arr[i];
    }

    int merge_idx = left;
    int idx1 = left;
    int idx2 = mid+1;

    while(idx1<=mid && idx2<=right){ // 왼, 오중 하나가 다 빠져나갈때까지는 비교를 계속 해야함
        count += 1;
        if(tmp[idx1] <= tmp[idx2]) { // 비교해서 작은거부터 추가하고 추가해야하는 위치 +1, 빠진 쪽에서 비교해야할 위치 +1
            arr[merge_idx++] = tmp[idx1++];
        }
        else arr[merge_idx++] = tmp[idx2++];
    }
    // 둘 중 하나가 다 빠지고 나면 남아있는걸 그대로 추가해주면 됨
    while(idx1 <= mid) 
    {
        arr[merge_idx++] = tmp[idx1++];
    }
    while(idx2 <= right)
    {
        arr[merge_idx++] = tmp[idx2++];
    }
}

void mergeSort(int arr[], int left, int right){ // 재귀저으로 merge
    if(left == right) return ;

    int mid = (left + right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid+1, right);
    merge(arr, left, mid, right);
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
    mergeSort(arr,0, n-1); 
        cout << count << endl;

    }
	return 0;
}