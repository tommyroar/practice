#include <iostream>
#include <vector>
#include <queue>

#define CALL std::cout<< __FUNCTION__ <<std::endl;

using namespace std;

typedef vector < vector <int> > vvi;
typedef vector <int> vi;

class Graph {
    int size;
    vvi adj;
    
    public:
        Graph(int size);
        void addEdge (int from, int to);
        bool bipartite ();
};

Graph::Graph (int size) {
    this->size = size;
    adj.resize(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
}

bool Graph::bipartite () {
    vi color(size, -1);
    queue <int> Q;
    color[0] = 0;
    Q.push(0);
    
    vi::iterator iter;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        
        for (iter = adj[u].begin(); iter != adj[u].end(); ++iter) {
            int v = *iter;
            if (color[v] == -1) {
                color[v] = 1 - (color[u]);
                Q.push(v);
            }
            else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

int main (int argc, char** argv) {
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    if (g.bipartite())
        cout << "Graph is bipartite" << endl;
    else
        cout << "Graph cannot be 2-colored" << endl;
    
    return 0;
}