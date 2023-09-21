#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n){ // 기본 알고리즘
    int comp = 0; 
    int swap = 0;
    for(int i = 1; i<n; i++) // 패스의 횟수 배열의 크기만큼 해야함
    {
        for(int j = 1; j<=n-i; j++) // 한번의 패스, 뒤부터 정리된 숫자를 제외한 숫자까지 진행
        {
            comp = comp + 1;
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swap = swap + 1;
            }
        }
    }
    cout << comp << " " << swap << " ";
}

void bubbleSort1(int arr[], int n){ // 개선 1, 패스에서 한번도 스왑을 안하면 정렬된 것으로 판단, 종료
    int comp = 0;
    int swap = 0;
    for(int i = 1; i<n; i++)
    {
        bool swaped = false; // 패스를 들어가기전 설정
        for(int j = 1; j<=(n-i); j++)
        {
            comp = comp + 1;
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swap = swap + 1;
                swaped = true; // 패스 내에서 교환이 있으면 계속 해야함
            }
        }
        if(swaped == false) // 교환이 없었으면 종료
        {
            break;
        }
    }
    cout << comp << " " << swap << " ";
}


void bubbleSort2(int arr[], int n){ // 개선 2, 마지막 교환한 위치를 저장 그 다음 패스에서 그 전까지만 진행
    int comp = 0;
    int swap = 0;
    int lastswaped = n;
    while(lastswaped > 0) // 마지막 교환 위치가 맨앞으로 올때까지 진행
    {
        int swapindex = 0;
        for(int j = 1; j<lastswaped; j++)
        {
            comp = comp + 1;
            if(arr[j] < arr[j-1])
            {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                swap = swap+1;
                swapindex = j; // 현재 패스에서의 교환 위치
            }
        }
    lastswaped = swapindex; // 패스 종료 후 마지막으로 교환한 위치를 갱신함
    }
    cout << comp << " " << swap << endl;
}


int main(){
    int t;
    cin >> t; //테스트 케이스 개수 입력
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int arr[n]; //배열 선언
        int arr1[n];
        int arr2[n];
        for (int j=0; j<n; j++)
        {
            int num;
            cin >> num;
            arr[j] = num;
            arr1[j] = num;
            arr2[j] = num;
        }
        bubbleSort(arr, n);
        bubbleSort1(arr1, n);
        bubbleSort2(arr2, n);
    }

	return 0;
}