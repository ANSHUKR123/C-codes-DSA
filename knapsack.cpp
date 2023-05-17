#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 Knapsack 
int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
    // Initialize a 2D vector dp to store the maximum value that can be obtained for a given capacity and item index
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Fill the dp table
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=W; j++) {
            if(wt[i-1] <= j) {  // if the current item can fit in the remaining capacity
                // choose the maximum value between including the current item and excluding the current item
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            } else {  // if the current item cannot fit in the remaining capacity
                // exclude the current item
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // Return the maximum value that can be obtained using n items and a knapsack of capacity W
    return dp[n][W];
}

int main() {
    // Sample input values
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int W = 50;
    int n = wt.size();

    // Call the knapsack function and print the result
    int max_val = knapsack(W, wt, val, n);
    cout << "Maximum value that can be obtained: " << max_val << endl;

    return 0;
}
