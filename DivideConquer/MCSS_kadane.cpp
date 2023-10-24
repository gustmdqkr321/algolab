#include <iostream>
using namespace std;

void kadane(int arr[], int len)
{
    int max = 0;
    int current = 0;
    int start, last;
    // length를 따로 구할 필요가 없는 이유 : 값이 같은경우 처음 인덱스가 가장 작은것이 1순위이고 
    // max값이 변화할떄만 start, last를 바꾸기 때문
    int j = 0; // start의 위치 저장용
    for(int i = 0; i<len; i++)
    {
    
        current = current + arr[i]; // current는 현재 구간
        if(max < current) // 한번 더할때마다 max보다 커지는지 체크 
        {
            max = current;
            last = i;
            start = j;
        }
        else if(current < 0) // -1이 될때만 시작위치를 변경
        {
            current = 0;
            j = i+1;
            if(arr[j] == 0) // 시작위치를 재설정할떄 0부터 시작하면 의미가 없으므로 건너뛰기 위함
            {
                j++;
                i++;
            }
        }
    }
    if(max <= 0)
    {
        cout << 0 << " " << -1 << " " << -1 << endl;
    }
    else
    {
        cout << max << " " << start << " " << last << endl;
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
        for(int j=0; j<n; j++) // 배열 입력 받기
        {
            cin >> arr[j];
        }
        kadane(arr,n);
    }


	return 0;
}