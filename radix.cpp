#include <iostream>
#include <vector>
using namespace std;

// Find the maximum element in the array
int getMax(vector<int>& arr) {
    int maxVal = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Counting sort function to sort the elements based on the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();

    // Create an array to store the count of digits and initialize it to 0
    int count[10] = {0};

    // Count the occurrences of each digit in the input array
    for(int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calculate the cumulative count of digits
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted array
    vector<int> sortedArr(n);
    for(int i = n - 1; i >= 0; i--) {
        sortedArr[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the sorted array to the original array
    for(int i = 0; i < n; i++) {
        arr[i] = sortedArr[i];
    }
}

// Radix Sort function
void radixSort(vector<int>& arr) {
    int maxVal = getMax(arr);

    // Sort the elements based on each digit
    for(int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

int main() {
    // Sample input array
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Unsorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    radixSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
