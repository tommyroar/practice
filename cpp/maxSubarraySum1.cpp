#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum (const vector <int> V) {
    int max_overall = 0;
    int max_here = 0;
    
    for (int i=0; i<V.size(); ++i) {
        max_here += V[i];
        if (max_here < 0) {
            max_here = 0;
        }
        if (max_overall < max_here) {
            max_overall = max_here;
        }
    }
    
    return max_overall;
}

int main (int argc, char** argv) {
    vector <int> V = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Max subarray sum: " << maxSubArraySum(V) << endl;
    return 0;
}