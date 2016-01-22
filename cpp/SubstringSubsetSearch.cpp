#include <iostream>
#include <queue>

#define CALL std::cout<<__FUNCTION__<<std::endl;
#define CSZ 256

using namespace std;

void search (string pat, string txt) {
    int M = pat.length();
    int N = txt.length();
    char patCharCount[CSZ] = {0};
    char txtCharCount[CSZ] = {0};
    for (int i=0; i<M; ++i) {
        (patCharCount[pat[i]])++;
        (txtCharCount[txt[i]])++;
    }
    
    bool found;
    for (int i=M; i<N; ++i) {
        found = true;
        for (int j=0; j<CSZ; ++j) {
            if (patCharCount[j] != txtCharCount[j]) {
                found = false;
            }
        }
        if (found) {
            cout << "Found pattern at index: " << (i-M) << endl;
        }
        (txtCharCount[txt[i]])++;
        (txtCharCount[txt[i-M]])--;
    }
    
    found = true;
    for (int j=0; j<CSZ; ++j) {
        if (patCharCount[j] != txtCharCount[j]) {
            found = false;
        }
    }
    if (found) {
        cout << "Found pattern at index: " << (N-M) << endl;
    }
}

int main (int argc, char** argv) {
    string txt = "BACDGABCDA";
    string pat = "ABCD";
    search(pat, txt);
    return 0;
}