#include <iostream>
using namespace std;

int BS(int arr[], int s, int f, int target)
{
    int len = f-s;
    if(len == 0)
    {
        return -1;
    }
    else
    {
        int mid = (s+f)/2;
        if(arr[mid] == target){
            return mid;
        }
        else if(arr[mid > target])
        {
            BS(arr,s,mid,target);
        }
        else
        {
            BS(arr,mid+1,f,target);
        }
    }
}


int main() {
    int n, target;
    cin >> target >> n;
    int arr[n];
    for(int i =0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << BS(arr,0,n-1, target);
    return 0;
}