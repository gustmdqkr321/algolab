#include <iostream>
using namespace std;

int max(int a, int b, int c) // 3개 비교
{
    if(a > b)
    {
        if(a >= c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b >= c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}
int middle_max(int arr[], int start, int last) // 중간에 걸쳐있는 최대값 
// 분할후 왼,오, 왼,오에 걸쳐있는 최대순열을 찾고 그중에 최대값을 계속 사용하는 방법
// 전체 길이의 최대값은 위의 3가지중 반드시 하나에 속하기 때문
{
    int middle = (start + last)/2;
    int left,right;
    left = 0;
    right = 0;
    int sum = 0;
    for(int i=middle; i>=start; i--) // 중간에 걸친 최대값을 찾는거기 떄문에 middle부터 시작해야함 반드시 i--로
    {
        sum = sum + arr[i]; // 한칸씩 더하면서 최대값찾기
        if(left < sum)
        {
            left = sum;
        }
    }
    sum = 0;
    for(int j=middle+1; j<=last; j++) // 중간부터 뒤로 가면서 최대값찾기
    {
        sum = sum + arr[j];
        if(right < sum)
        {
            right = sum;
        }
    }
    return left + right; // 두개를 더해야 중간에서 뻗어나가는 값중 최대값
}
int MCSS_DC(int arr[], int start, int last)
    {
        int len = last - start; 
        if(len == 0) // 분할 완료시 한개의 값 그대로 리턴
        {
            return arr[start];  
        }
        else
        {
            int middle = (start + last)/2;
            return max(MCSS_DC(arr,start,middle),MCSS_DC(arr,middle+1,last),middle_max(arr,start,last));
            // 왼,오,중간에 걸쳐있는 값중 최대값을 반환
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
        int sol = MCSS_DC(arr,0,n-1);
        if(sol <= 0)
        {
            sol = 0;
        }
        cout << sol << endl; 
    }


	return 0;
}