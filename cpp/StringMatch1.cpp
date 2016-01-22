#include <iostream>
#include <string.h>

using namespace std;

void search(string pat, string txt) {
    int p_sz = pat.length();
    int t_sz = txt.length();
    int j;
    
    for (int i=0; i<=(t_sz-p_sz); ++i) {
        for (j=0; j<p_sz; ++j) {
            if (txt[i+j] != pat[j]) {
                break;
            }
        }
        if (j==p_sz) {
            cout << "found string at index " << i << endl;
        }
    }
}

int main (int argc, char** argv) {
    string s1 = "whole lotta apples";
    string p1 = "lott";
    search(p1, s1);
    
    return 0;
}