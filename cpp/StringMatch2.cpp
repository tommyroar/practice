#include <iostream>

using namespace std;

void search(string pat, string txt) {
    int t_sz = txt.length();
    int p_sz = pat.length();
    int p_hsh = 0;
    int t_hsh = 0;
    int h = 1;
    int i, j;
    const int d = 256; //possible characters
    const int q = 101; //prime num
    
    for (i=0; i<p_sz-1; ++i) {
        h = (h*d)%q;
    }
    
    for (i=0; i<p_sz; ++i) {
        p_hsh = (d*p_hsh + pat[i])%q;
        t_hsh = (d*t_hsh + txt[i])%q;
    }
    
    for (i=0; i<=(t_sz-p_sz); ++i) {
        if (p_hsh == t_hsh) {
            for (j=0; j<p_sz; ++j) {
                if (txt[i+j] != pat[j]) {
                    break;
                }
            }
            if (j==p_sz) {
                cout << "found string at index " << i << endl;
            }
        }
        if (i<(t_sz-p_sz)) {
            t_hsh = (d*(t_hsh - txt[i] * h) + txt[i+p_sz])%q;
            if (t_hsh<0) {t_hsh= (t_hsh+q);}
        }
    }
}

int main (int argc, char** argv) {
    string s1 = "whole lotta apples";
    string p1 = "lott";
    search(p1, s1);
    
    return 0;
}