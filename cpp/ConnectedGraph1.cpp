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
        bool isConnected (int vertex);
};

Graph::Graph (int size) {
    this->size = size;
    adj.reserve(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
}

bool Graph::isConnected (int vertex) {
    vector <bool> visited(size, false);
    queue<int> Q;
    
    Q.push(vertex);
    visited[vertex] = true;
    
    int i;
    vector <int>::iterator iter;
    while (!Q.empty()) {
        i = Q.front();
        Q.pop();
        
        for (iter = adj[i].begin(); iter != adj[i].end(); ++iter) {
            cout << "visited " << *iter << endl;
            visited[*iter] = true;
            Q.push(*iter);
        }
    }
    
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