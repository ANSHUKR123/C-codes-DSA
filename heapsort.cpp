#include <iostream>
#include <vector>

using namespace std;

// Heapify function to maintain the heap property
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize the root as the largest element
    int left = 2 * i + 1;  // Calculate the left child index
    int right = 2 * i + 2;  // Calculate the right child index
    // If left child is larger than root, update the largest index
    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far, update the largest index
    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if(largest != i) {
        swap(arr[i], arr[largest]);  // Swap the root with the largest element
        heapify(arr, n, largest);  // Recursively heapify the affected subtree
    }
}

// Heap Sort function to sort the array
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap from the array
    for(int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from the heap
    for(int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move the root (largest element) to end of array
        heapify(arr, i, 0);  // Heapify the reduced heap
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    cout << "Unsorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
