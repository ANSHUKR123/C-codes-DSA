#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<float> buckets[n];

    // Fill buckets with elements
    for(int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i];
        buckets[bucketIndex].push_back(arr[i]);
    }

    // Sort each bucket
    for(int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // Concatenate all buckets into one array
    int index = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    vector<float> arr = {0.8, 0.2, 0.6, 0.4, 0.1, 0.9, 0.3, 0.5, 0.7};
    cout << "Unsorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ,";
    }
    cout << endl;

    bucketSort(arr);

    cout << "Sorted array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;

    return 0;
}
