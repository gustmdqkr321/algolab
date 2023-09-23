#include <iostream>
using namespace std;


void reverse_str(char s[], int first, int last){ // 맨앞과 맨 뒤를 바꾸는 것부터 시작
    if(first < last)
    {
        char temp = s[first];
        s[first] = s[last];
        s[last] = temp;
        reverse_str(s, first+1, last-1); // 비교하는 문자를 하나씩 당겨옴
    }
    else // 비교하는 문자가 같아지거나 한칸 떨어진 문자를 비교한 다음 단계에서 앞 뒤가 바뀌는 경우
    {
        return;
    }
}

int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력
    for (int i=0; i<t; i++)
    {
        char s[101];
        cin >> s;
        int size = 0;
        while(s[size]>='a' && s[size]<='z') // 입력 문자열 길이
        { 
            size++;
        }
        reverse_str(s,0,size-1);
        for(int k=0; k<size; k++)
        {
            cout << s[k];
        }
        cout << endl;
    }

	return 0;
}