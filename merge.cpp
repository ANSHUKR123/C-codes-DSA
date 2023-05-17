#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays into a single sorted array
// The left subarray is arr[l..m] and the right subarray is arr[m+1..r]
// Total number of comparisons: r-l+1
void merge(vector<int>& arr, int l, int m, int r) {
    // Create temporary arrays to hold the left and right subarrays
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1);
    vector<int> R(n2);

    // Copy data to the temporary arrays
    for(int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Merge the temporary arrays back into arr[l..r]
    int i = 0; // Index of the left subarray
    int j = 0; // Index of the right subarray
    int k = l; // Index of the merged array
    while(i < n1 && j < n2) {
        // Compare the next elements in the left and right subarrays
        // Choose the smaller element and add it to the merged array
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy any remaining elements from the left subarray
    while(i < n1) {
        arr[k++] = L[i++];
    }

    // Copy any remaining elements from the right subarray
    while(j < n2) {
        arr[k++] = R[j++];
    }
}

// Sorts arr[l..r] using merge()
// Total number of comparisons: nlogn
void mergeSort(vector<int>& arr, int l, int r, int& comparisons) {
    if(l < r) {
        // Find the middle point to divide the array into two subarrays
        int m = l + (r - l) / 2;

        // Recursively sort the two subarrays
        mergeSort(arr, l, m, comparisons);
        mergeSort(arr, m + 1, r, comparisons);

        // Merge the sorted subarrays
        merge(arr, l, m, r);

        // Increment the total number of comparisons
        comparisons += r - l + 1;
    }
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int comparisons = 0;

    // Sort the array using merge sort
    mergeSort(arr, 0, arr.size() - 1, comparisons);

    // Print the sorted array and the total number of comparisons
    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total number of comparisons: " << comparisons << endl;

    return 0;
}
