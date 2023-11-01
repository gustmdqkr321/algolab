#include <iostream>
using namespace std;

int c[100];
int l[100];

int rsol(int coins[], int noc, int change)
{
    if (c[change] < 11111)
    {
        return c[change];
    }
    if (change == 0)
    {
        c[0] = 0;
        return 0;
    }
    int mincoin = 11111;
    for (int i = 0; i < noc; i++)
    {
        if (change - coins[i] >= 0)
        {
            int temp = rsol(coins, noc, change - coins[i]) + 1;
            if (mincoin > temp)
            {
                mincoin = temp;
            }
        }
    }
    c[change] = mincoin;
    return c[change];
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, change;
        cin >> change;
        cin >> n;
        int coins[n];
        for (int j = 0; j < n; j++)
        {
            cin >> coins[j];
        }
        for (int j = 0; j <= change; j++)
        {
            c[j] = 11111;
            l[j] = 11111;
        }
        cout << rsol(coins, n, change) << endl;
    }
}
