#include <iostream>
using namespace std;

#define MAX 101

void order(int P[][MAX], int i, int j){
    if(i == j){
        cout << "M" << i;
    }
    else{
        int k = P[i][j];
        cout << "(";
        order(P, i, k);
        order(P, k+1, j);
        cout << ")";
    }
}

int CMM(int M[], int n, int P[][MAX]){
    int DP[MAX][MAX];

    for(int diagonal=1; diagonal<=n; diagonal++){
        for(int i=1; i<=n; i++){
            int j = diagonal + i;
            DP[i][j] = __INT_MAX__;
            for(int k=i; k<j; k++){
                int cnt = DP[i][k]+DP[k+1][j] + M[i-1]*M[k]*M[j];
                if(DP[i][j] > cnt){
                    DP[i][j] = cnt;
                    P[i][j] = k;
                }
            }
        }
    }

    order(P, 1, n);
    cout << '\n';

    return DP[1][n];
}



int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        int d[n+1];
        int P[MAX][MAX]; 
        for(int j=0; j<n+1; j++){
            cin >> d[j];
        }

        cout << CMM(d, n, P) << endl;
    }
    return 0;
}
