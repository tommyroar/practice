#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack (int cap, vector <int> val, vector <int> wt, int index) {
    if (index == 0 || cap == 0) {
        return 0;
    }
    
    if (wt[index-1] > cap) {
        return knapsack(cap, val, wt, index-1);
    }
    else {
        return max( val[index-1] + knapsack(cap-wt[index-1], val, wt, index-1),
                    knapsack(cap, val, wt, index-1));
    }
}

int main (int argc, char** argv) {
    vector <int> val = {60, 100, 120};
    vector <int> wt = {10, 20, 30};
    int cap = 50;
    cout << "Maximum val in knapsack: " << knapsack(cap, val, wt, val.size()) << endl;
    
    return 0;
}