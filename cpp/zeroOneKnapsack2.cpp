#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack (int cap, vector <int> val, vector <int> wt, int index) {
    int i = 0;
    int w = 0;
    int dp[index+1][cap+1];
    
    for (i=0; i<=index; ++i) {
        for (w=0; w<=cap; ++w) {
            if (i==0 || w==0) {
                dp[i][w] = 0;
            }
            else if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            } 
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[index][cap];
}

int main (int argc, char** argv) {
    vector <int> val = {60, 100, 120};
    vector <int> wt = {10, 20, 30};
    int cap = 50;
    cout << "Maximum val in knapsack: " << knapsack(cap, val, wt, val.size()) << endl;
    
    return 0;
}