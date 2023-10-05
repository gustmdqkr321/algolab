#include <iostream>
using namespace std;


void swap(char* arr, int i, int j){  // 스왑
  char tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void reverse_str(char s[], int first, int last){ // 맨앞과 맨 뒤를 바꾸는 것부터 시작
    if(first < last)
    {
        swap(s,first,last);
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
    int n;
    char string[27];
    for (int i=0; i<t; i++)
    {
        cin >> n >> string;
        int size = n;
        int swap_index = size;
        int min_index = size;
        for(int j = size; j>0; j--)
        {
            if(string[j] > string[j-1])
            {
                swap_index = j-1;
                break;
            }
        }
        for(int z = size; z>swap_index; z--)
        {
            if(string[z] > string[swap_index])
            {
                min_index = z;
                break;
            }
        }
        if(swap_index == size)
        {
            reverse_str(string,0,size-1);
        }
        else
        {
            swap(string, swap_index, min_index);
            reverse_str(string, swap_index+1, size-1);
        }
        for(int x = 0; x<size; x++)
        {
            cout << string[x];
        }
        cout << endl;
    }


	return 0;
}