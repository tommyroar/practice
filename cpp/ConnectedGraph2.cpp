#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
    vector < vector <int> > adj;
    int size;
    public:
        Graph(int size);
        void addEdge(int from, int to);
        void dfs(int vertex, vector <bool> &visited);
        bool isConnected (int vertex);
};

Graph::Graph (int size) {
    this->size = size;
    adj.reserve(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
}

void Graph::dfs (int vertex, vector <bool> &visited) {
    if (!visited[vertex]) {
        visited[vertex] = true;
        cout << "visited " << vertex << endl;
        vector <int>::iterator iter;
        for (iter = adj[vertex].begin(); iter != adj[vertex].end(); ++iter) {
            dfs(*iter, visited);
        }
    }
}

bool Graph::isConnected (int vertex) {
    vector <bool> visited(size, false);
    
    dfs(vertex, visited);

    return (find(visited.begin(), visited.end(), 0) == visited.end());
}

int main (int argc, char** argv) {
    int V = 9;
    Graph g(V);
    //g.addEdge(7, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(2, 5);
    g.addEdge(5, 7);
    g.addEdge(4, 7);
    g.addEdge(7, 8);
    if (g.isConnected(1)) { cout << "connected graph" << endl; }
    else { cout << "unconnected graph" << endl; }
    
    return 0;
}