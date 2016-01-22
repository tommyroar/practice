#include <iostream>

using namespace std;

int hammingDistance (unsigned int x, unsigned int y) {
    int dist = 0;
    unsigned int val = x ^ y;

    while (val != 0) {
        //bit set, increment count and clear bit
        ++dist;
        val &= val - 1;
    }
    
    return dist;
}

int main (int argc, char** argv) {
    unsigned int i1 = 2173896;
    unsigned int i2 = 2233796;
    cout << "hamming distance of " << i1 << " and " << i2 
        << ": " << hammingDistance(i1, i2) << endl;
    
    return 0;
}