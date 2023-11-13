#include <iostream>
#include <string>
using namespace std;

int sol(int coins[], int numofcoin, int change)
{
    if(change == 0)
    {
        return 0;
    }
    else if(change < 0)
    {
        return 12345;
    }
    else
    {
        int mincoin = change;
        for(int i=0; i<numofcoin; i++)
        {
            if(mincoin > sol(coins, numofcoin, change-coins[i]))
            {
                mincoin = sol(coins, numofcoin, change-coins[i]);
            }
        }
        return mincoin +1;
    }
}

int main() 
{
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int change;
        cin >> change;
        int noc;
        cin >> noc;
        int coins[noc];
        for(int i=0; i<noc;i++)
        {
            cin >> coins[i];
        }
        cout << sol(coins, noc, change) << endl;
    }
}