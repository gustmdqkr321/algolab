#include <iostream>
using namespace std;

int find_peak(int arr[], int i, int j)
{
    if (i == j) {
        return i; // Base case: single element, return its index
    }

    int mid = (i + j) / 2;

    if (arr[mid] > arr[mid + 1]) {
        // If the mid element is greater than the next element, there's a peak on the left side
        return find_peak(arr, i, mid);
    } else {
        // Otherwise, there's a peak on the right side
        return find_peak(arr, mid + 1, j);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int peak_index = find_peak(arr, 0, n - 1);
    cout << "Peak is at index " << peak_index << " with value " << arr[peak_index] << endl;
    return 0;
}
