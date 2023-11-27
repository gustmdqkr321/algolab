#include <iostream>
#include <string>
using namespace std;

#define MAX 100

int LCS(int mem[][MAX], char* a,char* b, int m, int n)
{
    if(m == 0 || n == 0)
    {
        mem[0][0] = 0;
        return 0;
    }
    else if(a[m-1] == b[n-1])
    {
        if(mem[m-1][n-1] != -1)
        {
            return mem[m-1][n-1];
        }
        else
        {
            mem[m-1][n-1] = LCS(mem,a,b,m-1,n-1) + 1;
            return mem[m-1][n-1];
        }
    }
    else
    {
        if(mem[m-1][n-1] != -1)
        {
            return mem[m-1][n-1];
        }
        else
        {
        mem[m-1][n-1] = max(LCS(mem,a,b,m,n-1), LCS(mem,a,b,m-1,n));
        return mem[m-1][n-1];
        }
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
        int mem[MAX][MAX];
        for(int j=0; j<lena; j++)
        {
            for(int k=0; k<lenb; k++)
            {
                mem[j][k] = -1;
            }
        }
        cout << LCS(mem,a,b,lena,lenb) << endl;
    }
    return 0;
}