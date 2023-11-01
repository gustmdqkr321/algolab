# include <iostream>
using namespace std;

int arr[100][100];

int rsol(int n, int k)
{
    if(arr[n][k] != -1)
    {
        return arr[n][k];
    }
    else
    {
        if(k==0 ||n == k)
        {
            arr[n][k] = 1 % 1000;
                return 1 % 1000;
        }
        else
        {
            arr[n][k] = (rsol(n-1,k) + rsol(n-1,k-1));
            return arr[n][k] % 1000;
        }
            }
}


int sol(int n, int k)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            arr[i][j] = -1;
        }
    }
    return rsol(n,k);
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << sol(n,k);
}