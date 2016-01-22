#include <iostream>
#include <vector>

#define CALL std::cout<< __FUNCTION__ <<std::endl;

using namespace std;

int uniqueVal (vector <int> V) {
    int result = 0;
    for (int i=0; i<V.size(); ++i) {
        result ^= V[i];
    }
    return result;
}

int main (int argc, char** argv) {
    vector <int> V = {2, 3, 7, 11, 2, 3, 11};
    cout << "non-repeated element is: " << uniqueVal(V) << endl;

    return 0;
}