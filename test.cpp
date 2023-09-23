#include <iostream>
using namespace std;


void reverse_str(char s[], int first, int last){ // 기본 알고리즘
    if(first < last)
    {
        char temp = s[first];
        s[first] = s[last];
        s[last] = temp;
    }
    else
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