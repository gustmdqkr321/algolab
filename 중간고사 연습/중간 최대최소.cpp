#include <iostream>
using namespace std;

int count_recursive_call = 0;

void FindMinMax(int a[], int low, int high, int& max, int& min) {
    count_recursive_call++;
    int min1, min2, max1, max2;
    int len = high - low;
    if (len == 0) {
        max = a[low];
        min = a[low];
    } 
    else if (len == 1) {
        if (a[low] > a[high]) {
            min = a[high];
            max = a[low];
        } else {
            min = a[low];
            max = a[high];
        }
    } 
    else {
        int mid = (low + high) / 2;
        FindMinMax(a, low, mid, max1, min1);
        FindMinMax(a, mid + 1, high, max2, min2);

        if (max1 > max2) max = max1;
        else max = max2;
        if (min1 < min2) min = min1;
        else min = min2;
    }
}

int main() {
    int num_test_cases;
    int data[100], size;
    cin >> num_test_cases;
    while (num_test_cases--) {
        cin >> size; 
        count_recursive_call = 0; 
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
        int min, max;
        FindMinMax(data, 0, size - 1, max, min);
        cout << max << " " << min << " " << count_recursive_call << endl;
    }
}
