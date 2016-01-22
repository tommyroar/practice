#include <iostream>
#include <map>

using namespace std;

void search(string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    map <string, int> mapa;
    
    for (int i=0; i<(N-M); ++i) {
        mapa[txt.substr(i,M)] = i;
    }
    if (mapa.count(pat)>0) {
        cout << "pattern found at index " << mapa[pat] << endl;
    }
}

int main (int argc, char** argv) {
    string s1 = "whole lotta apples";
    string p1 = "lott";
    search(p1, s1);
    
    return 0;
}