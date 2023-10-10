#include <iostream>
using namespace std;

int Binary_Search(int arr[], int start, int last,int k)
{
    int len = last - start; // 분할 후의 길이 
    if(len == 0) // 0일때 같아야 값이 있는것
    {
        if(arr[start] == k)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int middle = (start + last)/2; // 가운데 인덱스 구하고 중간값이 찾는값이면 인덱스 리턴 크면 그 뒤만 탐색 작으면 앞에만 탐색
        if(arr[middle] > k)
        {
            Binary_Search(arr, start, middle,k);
        }
        else if(arr[middle] < k)
        {
            Binary_Search(arr, middle+1, last,k);
        }
        else
        {
            return middle;
        }
    }
}
int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력 
    int n,k;
    for (int i=0; i<t; i++)
    {
        cin >> n >> k;
        int arr[101];
        for(int j=0; j<n; j++)
        {
            cin >> arr[j];
        }
        cout << Binary_Search(arr,0,n-1,k) << endl; // n은 정수의 개수고 인덱스는 0부터라 n-1로해야함
    }


	return 0;
}