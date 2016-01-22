#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArraySum (const vector <int> V) {
    int max_overall = V.front();
    int max_here = max_overall;
    
    for (int i=0; i<V.size(); ++i) {
        max_here = max(V[i], max_here+V[i]);
        max_overall = max(max_overall, max_here);
    }
    
    return max_overall;
}

int main (int argc, char** argv) {
    vector <int> V = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout << "Max subarray sum: " << maxSubArraySum(V) << endl;
    return 0;
}