#include <iostream>
#include <vector>

using namespace std;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector < vi > vvi;

class Graph {
    int size;
    vvi adj;
    
    public:
        Graph(int size);
        void addEdge (int from, int to);
        void _eulerPath (int vertex, vb &visited);
        bool eulerPath ();
};

Graph::Graph (int size) {
    this->size = size;
    adj.resize(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
    adj[to].push_back(from);
}

void Graph::_eulerPath (int vertex, vb &visited) {
    //visit all nodes to determine if graph connected
    visited[vertex] = true;
    for (vi :: iterator it = adj[vertex].begin(); it != adj[vertex].end(); ++it) {
        if (!visited[vertex]) {
            _eulerPath((*it), visited);
        }
    }
}

bool Graph::eulerPath () {
    vb visited(size, false);
    vvi :: iterator it;
    //count odd vertices
    int odd = 0;
    for (it = adj.begin(); it != adj.end(); ++it) {
        if ((*it).size() & 1) {
            odd++;
        }
    }
    if (odd > 2) {
        // >2 odd vertices not eulerian
        return false;
    }
    
    for (it = adj.begin(); it != adj.end(); ++it) {
        if ((*it).size()) {
            _eulerPath(it-adj.begin(), visited);
        }
    }
    
    for (vb :: iterator vbit = visited.begin(); vbit != visited.end(); ++vbit) {
        if ((*vbit) == false && adj[(*vbit)].size() > 0) {
            cout << "did not visit all deg>0 nodes" << endl;
            return false;
        }
    }
    return true;
}

int main (int argc, char** argv) {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,5);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(3,5);
    if (g.eulerPath()) {
        cout << "Euler path found" << endl;
    }
    else {
        cout << "Euler path not possible" << endl;
    }
    
    return 0;
}

