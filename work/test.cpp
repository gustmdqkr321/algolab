#include <iostream>
#include <string>
using namespace std;

#define MAX 11

int LCS(char* a,char* b, int m, int n)
{
    if(m == 0 || n == 0)
    {
        return 0;
    }
    else if(a[m-1] == b[n-1])
    {
        return LCS(a,b,m-1,n-1) + 1;
    }
    else
    {
        return max(LCS(a,b,m,n-1), LCS(a,b,m-1,n));
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        char a[MAX];
        char b[MAX];
        int lena = 0;
        int lenb = 0;
        cin >> a >> b;
        while(a[lena] != '\0') 
        {
            lena++;
        }
        while(b[lenb] != '\0') 
        {
            lenb++;
        }
        cout << LCS(a,b,lena,lenb) << endl;
    }
    return 0;
}