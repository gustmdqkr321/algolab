#include <iostream>
#include <string>
using namespace std;

#define MAX 101
int S[MAX][MAX];

int LCS(char* a, char* b, int m, int n) {
    int DP[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                DP[i][j] = 0;
            } else if (a[i - 1] == b[j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
                S[i][j] = 0;
            } else {
                int temp_a = DP[i - 1][j];
                int temp_b = DP[i][j - 1];
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
                if (DP[i][j] == temp_a) {
                    S[i][j] = 1;
                } else {
                    S[i][j] = 2;
                }
            }
        }
    }
    return DP[m][n];
}

void print_LCS(char* a, char* b, int m, int n) {
    if (m == 0 || n == 0) {
        return;
    }
    if (S[m][n] == 0) {
        print_LCS(a, b, m - 1, n - 1);
        cout << a[m - 1];
    } else if (S[m][n] == 1) {
        print_LCS(a, b, m - 1, n);
    } else {
        print_LCS(a, b, m, n - 1);
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        char a[MAX];
        char b[MAX];
        int lena = 0;
        int lenb = 0;
        cin >> a >> b;
        while (a[lena] != '\0') {
            lena++;
        }
        while (b[lenb] != '\0') {
            lenb++;
        }
        for (int j = 0; j <= lena; j++) {
            for (int k = 0; k <= lenb; k++) {
                S[j][k] = 0;
            }
        }
        cout << LCS(a, b, lena, lenb) << " ";
        print_LCS(a, b, lena, lenb);
        cout << endl;
    }
    return 0;
}
