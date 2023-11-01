# include <iostream>
using namespace std;

int fibo[100];
int rfib(int n)
{
    if(fibo[n] != -1)
    {
        return fibo[n];
    }
    else
    {
        if(n <= 1)
        {
            fibo[n] = n;
            return n;
        }
        fibo[n] = rfib(n-1) + rfib(n-2);
        return fibo[n];
    }
}
int fib(int n)
{
    for(int i=0; i<=n; i++)
    {
        fibo[i] = -1;
    }
    return rfib(n);
}
int main()
{
    int n;
    cin >> n;
    cout << fib(n);
}