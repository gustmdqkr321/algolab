#include <iostream>
using namespace std;

int arr[101][101];

int bc(int n, int k)
{
    for(int i = 0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            if(j == 0 || i == j)
            {
                arr[i][j] = 1%1000;
            }
            else
            {
                arr[i][j] = (arr[i-1][j] + arr[i-1][j-1])% 1000;
            }
        }
    }
    return arr[n][k]%1000;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        cout << bc(n,k) << endl;
    }
    return 0;
}
