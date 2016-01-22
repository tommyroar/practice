#include <iostream>
#include <vector>

using namespace std;

void computeLPS (string pat, int M, vector <int> &lps) {
    lps[0] = 0;
    int len=0;
    int i=1;
    
    while (i<M) {
        if (pat[i] == pat[len]) {
            ++len;
            lps[i] = len;
            ++i;
        }
        else {
            if (len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                ++i;
            }
        }
    }
}

void search(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    vector <int> lps(M, 0);
    
    computeLPS(pat, M, lps);
    
    int i=0;
    int j=0;
    
    while (i<N) {
        if (pat[j] == txt[i]) {
            ++j;
            ++i;
        }
        if (j == M) {
            cout << "found string at index " << i-j << endl;
            j = lps[j-1];
        }
        else if (i<N && pat[j]!=txt[i]) {
            if (j!=0) {
                j = lps[j-1];
            }
            else {
                ++i;
            }
        }
    }
}

int main (int argc, char** argv) {
    string s1 = "whole lotta apples";
    string p1 = "lott";
    search(p1, s1);
    
    return 0;
}