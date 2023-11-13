# include <iostream>
using namespace std;
int c[100];
int l[100];
int sol(int coins[], int change, int numofcoin)
{
    c[0] = 0;
    l[0] = 0;
    for(int i=0; i<=change; i++)
    {
        int mincoin = i;
        int newcoin = 1;
        for(int j=0; j<numofcoin; j++)
        {
            if(i-coins[j] < 0)
            {
                continue;
            }
            if(mincoin > c[i-coins[j]] + 1)
            {
                mincoin = c[i-coins[j]] + 1;
                newcoin = coins[j];
            }
        }
        c[i] = mincoin;
        l[i] = newcoin;
    }
    return c[change];
}
int main()
{
    int t;
    cin >> t;
    for(int i = 0; i<t; i++)
    {
        int change;
        cin >> change;
        int n;
        cin >> n;
        int coins[n];
        for(int j =0; j<n; j++)
        {
            cin >> coins[j];
        }
        cout << sol(coins, change, n) << endl;
    }
}