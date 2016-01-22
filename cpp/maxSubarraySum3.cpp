#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int max(int x, int y, int z) {
    return max(max(x, y), z);
}

int maxCrossingSum (const vector <int> V, int low, int mid, int high) {
    int sum = 0;
    int low_sum = INT_MIN;
    for (int i=mid; i>=low; --i) {
        sum += V[i];
        if (sum > low_sum) {
            low_sum = sum;
        }
    }
    sum = 0;
    int high_sum = INT_MIN;
    for (int j=mid+1; j<=high; ++j) {
        sum += V[j];
        if (sum > high_sum) {
            high_sum = sum;
        }
    }
    return low_sum + high_sum;
}

int maxSubArraySum (const vector <int> V, int low, int high) {
    if (low == high) {
        return V[low];
    }
    
    int mid = (low + high) / 2;
    
    return max(maxSubArraySum(V, low, mid),
                maxSubArraySum(V, mid+1, high),
                maxCrossingSum(V, low, mid, high));
}

int main (int argc, char** argv) {
    vector <int> V = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Max subarray sum: " << maxSubArraySum(V, 0, V.size()-1) << endl;
    return 0;
}