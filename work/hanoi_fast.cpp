#include <iostream>
#include <math.h>
using namespace std;

void hanoi(int n,int a,int b,int c,unsigned long long int count)
{
    if(n<=1)
    {
        cout << a << " " << c;
        return;
    }
    unsigned long long int t = pow(2, n-1); // n개의 원판을 모두 옮기는데 필요한 횟수
    if(t>count) // 원하는 숫자를 구할때 원판을 다 안옮겨도 되는 경우임
    {
        hanoi(n-1, a,c,b,count);  // 제일 큰 원판을 안 옮기고 숫자를 구할 수 있음 제일 큰 원판을 a->c하기 이전 단계인 n-1개를 a->b로 옮기는 단계
    }
    else if(t == count) // 같으면 마지막남은 원판을 옮기는 과정이기 떄문에 n이 1임
    {
       hanoi(1,a,b,c,count);
    }
    else // 조건 1에서 호출된 함수로 count를 구할 수 없을때 더 옮겨야 해서 
         // 1이 완료되기 위해 필요한 횟수 t를 뺸 후 완료된 후(n-1개를 b에서 c로 옮기는 과정) 부터 세는 것
    {
        hanoi(n-1, b,a,c,count - t); 
    }
}




int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력 
    int n;
    unsigned long long int count;
    for (int i=0; i<t; i++)
    {
        cin >> n >> count; // 문자 입력
        hanoi(n,1,2,3,count);
        cout << endl;
    }


	return 0;
}