#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int size;
    vector < vector <int> > G;
    void topoSortUtil(int vertex, vector <bool> visited, stack<int> &Sorted);
    void printBitVector (vector <bool> theVector);
    public:
        Graph(int size);
        void addEdge(int from, int to);
        void topoSort();
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

void Graph::topoSortUtil (int vertex, vector <bool> visited, stack<int> &Sorted) {
    visited[vertex] = true;
    printBitVector(visited);
    vector<int>::iterator iter;
    for (iter=G[vertex].begin(); iter!=G[vertex].end(); ++iter) {
        if (!visited[*iter]) {
            topoSortUtil (*iter, visited, Sorted);
        }
    }
    Sorted.push(vertex);
}

void Graph::topoSort () {
    stack<int> Sorted;
    vector<bool> visited(size, false);
    
    for (int i=0; i<size; ++i) {
        if(!visited[i]) {
            topoSortUtil(i, visited, Sorted);
        }
    }
    
    while (!Sorted.empty()) {
        cout << Sorted.top() << " ";
        Sorted.pop();
    }
    cout << endl;
}

int main (int argc, char** argv) {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.topoSort();
    
    return 0;
}