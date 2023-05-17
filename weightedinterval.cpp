#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start, end, weight;
    Interval(int start, int end, int weight) : start(start), end(end), weight(weight) {}
};

// Compare intervals based on their end time
bool compare(Interval& a, Interval& b) {
    return a.end < b.end;
}

// Find the latest non-overlapping interval with index less than j
int latestNonOverlapping(vector<Interval>& intervals, int j) {
    for(int i = j - 1; i >= 0; i--) {
        if(intervals[i].end <= intervals[j].start) {
            return i;
        }
    }
    return -1;
}

// Compute the maximum weight subset of mutually non-overlapping intervals
int weightedIntervalScheduling(vector<Interval>& intervals) {
    int n = intervals.size();

    // Sort intervals based on their end time
    sort(intervals.begin(), intervals.end(), compare);

    // Compute the maximum weight subset for each interval
    vector<int> maxWeight(n);
    maxWeight[0] = intervals[0].weight;
    for(int j = 1; j < n; j++) {
        int weight = intervals[j].weight;
        int i = latestNonOverlapping(intervals, j);
        if(i != -1) {
            weight += maxWeight[i];
        }
        maxWeight[j] = max(maxWeight[j-1], weight);
    }

    return maxWeight[n-1];
}

int main() {
    // Example usage
    vector<Interval> intervals = {Interval(0, 3, 5), Interval(2, 6, 3), Interval(3, 9, 4),
                                  Interval(5, 12, 6), Interval(8, 11, 2), Interval(10, 15, 5)};
    int maxWeight = weightedIntervalScheduling(intervals);
    cout << "Maximum weight subset: " << maxWeight << endl;
    return 0;
}
