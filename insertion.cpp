#include <iostream>
#include <vector>

using namespace std;

// Insertion Sort function to sort the array and count comparisons
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    int comparisons = 0;

    for(int i = 1; i < n; i++) {
        int current = arr[i];  // Store the current element in a current variable
        int j = i - 1;  // Initialize the comparison index to the previous element

        // Shift elements greater than current to the right
        while(j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
              // Increment comparison counter
            comparisons++;
        }
        comparisons++;

        arr[j + 1] = current;  // Insert the key element in the correct position
    }

    cout << "Number of comparisons: " << comparisons << endl;  // Output the number of comparisons
}

int main() {
    int size,m;
    vector<int> arr;
    cout<<"enter the size of array: "<<endl;
    cin>>size;
    cout<< "enter the input array : "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<"enter the array at index "<< i<<endl;
        cin>>m;
        arr.push_back(m);
    };
    
    cout << "Unsorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertionSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
