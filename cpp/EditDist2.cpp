#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int editDist (string s1, string s2, int m, int n) {
    static unordered_map <int, unordered_map <int, int> > memo;
    if (memo[m].count(n) > 0) {
        cout << "cache hit for " << m << " " << n << endl;
        return memo[m][n];
    }
    if (s1.substr(0,m) == s2.substr(0,n)) {
        memo[m].insert(make_pair(n, 0));
        return 0;
    }
    if (m == 0) {
        memo[m].insert(make_pair(n, n));
        return n;
    }
    if (n == 0) {
        memo[m].insert(make_pair(n, m));
        return m;
    }
    if (s1[m-1] == s2[n-1]) {
        int ret = editDist(s1, s2, m-1, n-1);
        memo[m].insert(make_pair(n, ret));
        return ret;
    }
    int ret =  1 + min ( min(editDist(s1, s2, m, n-1), //insert
                            editDist(s1, s2, m-1, n)), //remove
                        editDist(s1, s2, m-1, n-1)); //replace
    memo[m].insert(make_pair(n, ret));
    return ret;
}

int main() {
    string s1 = "tuesday";
    string s2 = "tuesday";
    cout << "Edit distance: " << editDist(s1, s2, s1.length(), s2.length()) << endl;
    
	return 0;
}