#include <iostream>
using namespace std;


int CMM(int m[], int i, int j) {
    if(i == j) return 0;

    int min = __INT_MAX__;
    int cnt;
    for(int k=i; k<j; k++){
        cnt = CMM(m, i, k) + CMM(m, k+1, j) + m[i-1]*m[k]*m[j];
        if(cnt < min) 
        {
            min = cnt;
        }
    }
    return min;
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
        cout << CMM(arr, 1, n) << endl;
    }
    return 0;
}
