#include <iostream>
using namespace std;

int sol(int arr[], int len)
{
    int max = 1;
    for(int i=0; i<len-1; i++){
        int cur = 1;
        for(int j=i; j<len-1; j++){
            if(arr[j] <= arr[j+1])
            {
                cur++;
            }
            else
            {
                break;
            }
        }
        if(max < cur)
        {
            max = cur;
        }
    }
return max;
}
int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력 
    int n;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        int arr[1001];
        for(int j=0; j<n; j++) // 배열 입력 받기
        {
            cin >> arr[j];
        }
        cout << sol(arr,n) << endl;
    }


	return 0;
}