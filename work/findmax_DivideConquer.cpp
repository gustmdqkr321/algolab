#include <iostream>
using namespace std;

int findmax(int arr[], int start, int last)
{
    int len = last - start; // 분할 후의 길이 
    if(len == 0) // 1말고 0 앞뒤가 같아야 1칸이니까
    {
        return arr[start]; // 1칸값 리턴
    }
    else
    {
        int middle = (start + last)/2; // 가운데 인덱스 구하고
        if(findmax(arr, start, middle) > findmax(arr, middle+1, last)) // 왼,오중 큰값 판별해서 큰값 리턴 1칸부터 올라오는 구조
        {
            return findmax(arr, start, middle);
        }
        else
        {
            return findmax(arr, middle+1, last);
        }
    }
}
int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력 
    int n;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        int arr[101];
        for(int j=0; j<n; j++)
        {
            cin >> arr[j];
        }
        cout << findmax(arr,0,n-1) << endl; // n은 정수의 개수고 인덱스는 0부터라 n-1로해야함
    }


	return 0;
}