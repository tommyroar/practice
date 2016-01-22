#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int size;
    vector < vector <int> > G;
    bool isCycleUtil(int vertex, vector <bool> visited, vector <bool> cycle);
    void printBitVector (vector <bool> theVector);
    public:
        Graph(int size);
        void addEdge(int from, int to);
        bool isCycle();
};

Graph::Graph(int size) {
    this->size = size;
    G.reserve(size);
}

void Graph::addEdge (int from, int to) {
    G[from].push_back(to);
}

void Graph::printBitVector (vector <bool> theVector) {
    for (vector<bool>::iterator iter = theVector.begin(); iter!=theVector.end(); ++iter) {
        cout << (*iter ? '1' : '0') << " ";
    }
    cout << endl;
}

bool Graph::isCycleUtil (int vertex, vector <bool> visited, vector <bool> cycle) {
    visited[vertex] = true;
    cycle[vertex] = true;
    
    //printBitVector(visited);
    vector<int>::iterator iter;
    for (iter=G[vertex].begin(); iter!=G[vertex].end(); ++iter) {
        if (!visited[*iter] && isCycleUtil(*iter, visited, cycle)) {
            return true;
        }
        else if (cycle[*iter]) {
            return true;
        }
    }
    cycle[vertex] = false;
    return false;
}

bool Graph::isCycle () {
    vector<bool> visited(size, false);
    vector<bool> cycle(size, false);
    
    for (int i=0; i<size; ++i) {
        if(isCycleUtil(i, visited, cycle)) {
            return true;
        }
    }
    return false;
}

int main (int argc, char** argv) {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    if (g.isCycle()) {
        cout << "cycle detected" << endl;
    }
    else {
        cout << "acyclic" << endl;
    }
    
    Graph h(6);
    h.addEdge(0, 1);
    h.addEdge(0, 2);
    h.addEdge(1, 2);
    h.addEdge(2, 0);
    h.addEdge(2, 3);
    h.addEdge(3, 3);
    if (h.isCycle()) {
        cout << "cycle detected" << endl;
    }
    else {
        cout << "acyclic" << endl;
    }
    
    return 0;
}