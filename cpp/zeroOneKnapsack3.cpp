#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

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

int knapsack_memo (int cap, vector <int> val, vector <int> wt, int index) {
    static map <int, int> memo;
    if (memo.count(index) > 0) {
        cout << memo[index] << " found in cache for " << index << endl;
        return (memo[index]);
    }
    if (index<0) {
        memo[index] = 0;
        return 0;
    }
    else {
        if (wt[index-1] > cap) {
            int ret = knapsack_memo(cap, val, wt, index-1);
            memo[index] = ret;
            return ret;
        }
        else {
            int ret_max = max( val[index-1] + knapsack_memo(cap-wt[index-1], val, wt, index-1),
                        knapsack_memo(cap, val, wt, index-1) );
            memo[index] = ret_max;
            return ret_max;
        }
    }
}

int main (int argc, char** argv) {
    vector <int> val = {60, 100, 120};
    vector <int> wt = {1, 2, 3};
    //vector <int> val = {894, 260, 392, 281, 27};
    //vector <int> wt = {8, 6, 4, 0, 21};
    int cap = 10;
    cout << "Maximum val in knapsack: (dp): " << knapsack(cap, val, wt, val.size()) << endl;
    cout << "Maximum val in knapsack (memo): " << knapsack_memo(cap, val, wt, val.size()) << endl;
    
    return 0;
}