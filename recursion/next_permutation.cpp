#include <iostream>
using namespace std;


void swap(char* arr, int i, int j){  // 스왑
  char tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

void reverse_str(char s[], int first, int last){ // 리버스, 처음 순열이나 교환후 교환 이후 인덱스를 뒤집을때 사용
    if(first < last)
    {
        swap(s,first,last);
        reverse_str(s, first+1, last-1); 
    }
    else 
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
        int swap_index = size; // 뒤에서부터 오름차순으로 찾은 순열의 바로 앞자리, 이 인덱스와 뒤의 순열의 최솟값(이 값보다는 큰)과 교환해야함 
        int min_index = size;  // 뒤의 순열중 string[swap_index]보다는 큰 최솟값을 찾아야함
        for(int j = size; j>0; j--) // 뒤에서부터 오름차순 순열 최대길이 찾기
        {
            if(string[j] > string[j-1]) // j보다, j-1이 작으면 오름차순을 만족하지 않기 때문에 종료
            {
                swap_index = j-1; // j까지가 순열
                break;
            }
        }
        for(int z = size; z>swap_index; z--) // 최솟값 찾기
        {
            if(string[z] > string[swap_index]) // swap_index전까지는 오름차순이므로 큰 조건만 만족하면 그 값이 만족하는 수중 최솟값임
            {
                min_index = z;
                break;
            }
        }
        if(swap_index == size) // swap_index가 size에서 변한적이 없으면 전체길이가 뒤에서부터 오름차순(가장 마지막 순열)
        {
            reverse_str(string,0,size-1); // 전체로 뒤집으면 첫번쨰 순열이 나옴
        }
        else
        {
            swap(string, swap_index, min_index); // 마지막 순열이 아니면 최소값과 위에서 찾은 오름차순 순열의 앞을 교환
            reverse_str(string, swap_index+1, size-1); // 교환후 그 뒤 위치는 최소로 만들어야 하기 떄문에 그 구간을 뒤집음
        }
        for(int x = 0; x<size; x++)
        {
            cout << string[x];
        }
        cout << endl;
    }


	return 0;
}