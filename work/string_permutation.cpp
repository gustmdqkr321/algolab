#include <iostream>
using namespace std;
int count_ord = 0; // 정답 전역변수로 설정, 함수로 바꿈


void swap(char* arr, int i, int j){  // 스왑
  char tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void ord(char* arr, int len) // 가중치 양수 음수 판별
{
    int w = 0; // 가중치
    for(int i=0; i<len; i++) // 문자열의 처음부터 마지막까지
    {
        if(i%2 == 0) // +부터 시작 처음걸 0번쨰로 계산
        {
            w = w + (int(arr[i]) - int('a')); // char to int는 그냥 가능
        }
        else // 인덱스 1,3,5일때는 -
        {
            w = w - (int(arr[i]) - int('a'));
        }
    }
    if(w > 0) 
    {
        count_ord++; // 전역변수로 양수인 순열의 개수 카운팅
    }
}

int permutation(char* arr, int first, int last, int len) // 문자순열 만들기 len은 문자열 만들고 가중치 계산할때 필요함
{
    int range = last - first; // 바꿀수 있는 수의 남은 칸으로 생각
    if(range == 1) // 0도 값은 똑같은데 마지막 자리끼리 바꾸는거라 의미없음 1로해야함
    {
        ord(arr,len); // 순열 완성되면 가중치 계산
    }
    else
    {
        for(int i=0; i<range; i++)
        {
            swap(arr,first,first+i);
            permutation(arr,first+1,last,len);
            swap(arr,first,first+i);
        }
    }
    return count_ord;
}


int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력
    char s[10]; // 입력받을 문자 
    for (int i=0; i<t; i++)
    {
        cin >> s; // 문자 입력
        int len = 0;
        while(s[len] != '\0') // 문자 길이 측정
        {
            len++;
        }
        cout << permutation(s,0,len,len) << endl;
        count_ord = 0;
    }

	return 0;
}