#include <iostream>
using namespace std;

#define MAX 101

int CMM(int mem[][MAX], int m[], int i, int j) {
    if(i == j) 
    {
        mem[i][j] = 0;
        return 0;
    }

    int min = __INT_MAX__;
    int cnt;
    if(mem[i][j] == -1){
        for(int k=i; k<j; k++){
            cnt = CMM(mem, m, i, k) + CMM(mem,m, k+1, j) + m[i-1]*m[k]*m[j];
            if(cnt < min) min = cnt;
            mem[i][j] = min;
        }
    }
    return mem[i][j];
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int arr[n+1];
        for(int j=0; j<=n;j++)
        {
            cin >> arr[j];
        }
        int mem[MAX][MAX];
        for(int j=0; j<MAX; j++)
        {
            for(int k=0; k<MAX; k++)
            {
                mem[j][k] = -1;
            }
        }
        cout << CMM(mem,arr, 1, n) << endl;
    }
    return 0;
}
