#include <iostream>
using namespace std;

int SF_MCSS(int arr[], int len)
{
    int length = 1; // 기본이 1
    int current = arr[0]; // 처음부터 시작해서 처음시작한 값보다 작은 값이 나올때까지 수열을 늘림
    int j = 0; // 지금 계산하는 수열의 처음 위치 작은값이 나오면 그 위치부터 새롭게 시작
    int max_len = 1; // 지금까지 계산된 수열중 최대값 저장
    for(int i=0; i<len-1; i++) 
    {
        if(current <= arr[i+1]) // 시작값보다 큰값이 나오면 
        {
            length++; // 수열 길이증가
            j++; // 큰 값은 다음에 시작할 필요가 없기 때문에 건너뛰어줌
            if(max_len < length) // 수열이 늘어날때마다 최대기링 수열과 비교
            {
                max_len = length;
            }
        }
        else // 작은값이 나오면 수열 초기화 및 시작위치 초기화
        {
            length = 1;
            current = arr[i+1];
        }
    }
    return max_len;
}


int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력
    int n;
    for (int i=0; i<t; i++)
    {
        cin >> n;
        int arr[1001];
        for(int j=0; j<n; j++)
        {
            cin >> arr[j];
        } 
    cout << SF_MCSS(arr,n) << endl;
    }
	return 0;
}