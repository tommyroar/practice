#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define CALL \
    std::cout<<__FUNCTION__<<std::endl;

using namespace std;

class Graph {
    int size;
    vector < vector < pair <int, int> > > adj;
    public:
        Graph(int size);
        void addEdge (int from, int to, int weight);
        void print(vector < vector <int> > mat);
        void APSP ();
};

Graph::Graph (int size) { 
    this->size = size;
    adj.reserve(size);
}

void Graph::addEdge (int from, int to, int weight) {
    adj[from].push_back(pair <int, int>(to, weight));
}

void Graph::APSP () {
    vector < vector <int> > mat;
    mat.resize(size, vector <int>(size, 0));
    int i, j, k;

    vector < pair <int,int> >::iterator iter;
    for (i=0; i<size; ++i) {
        for (j=0; j<size; ++j) {
            if (i!=j) {
                mat[i][j] = SHRT_MAX;
            }
        }
        for (iter = adj[i].begin(); iter != adj[i].end(); ++iter) {
            mat[i][iter->first] = iter->second;
        }
    }
    print(mat);
    
    for (k=0; k<size; ++k) {
        for (i=0; i<size; ++i) {
            for (j=0; j<size; ++j) {
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
    print(mat);
}

void Graph::print(const vector < vector <int> > adj) {
    cout << endl;
    for (vector < vector <int> >::const_iterator row = adj.begin(); row!=adj.end(); ++row) {
        for (vector <int>::const_iterator col = row->begin(); col != row->end(); ++col) {
            cout << *col << " ";
        }
        cout << endl;
    }
}

int main (int argc, char** argv) {
    Graph g(4);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 3, 10);
    g.addEdge(1, 2, 3);
    g.addEdge(2, 3, 1);
    g.APSP();
    
    return 0;
}