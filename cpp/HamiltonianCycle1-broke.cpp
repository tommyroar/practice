#include <iostream>
#include <vector>

#define CALL std::cout<<__FUNCTION__<<std::endl;

using namespace std;

class Graph {
    int size;
    vector < vector <int> > adj;
    
    public:
        Graph(int size);
        void addEdge (int from, int to);
        void print (vector <int> V);
        bool hamiltonPath (int vertex);
        bool hamiltonPathUtil (vector <int> &path, vector <bool> &visited, 
                                int steps, int vertex);
        bool vertexSafe(vector <int> path, int from, int to);
};

Graph::Graph (int size) {
    this->size = size;
    adj.resize(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
    adj[to].push_back(from);
}

void Graph::print (const vector <int> V) {
    for (vector <int>::const_iterator it = V.begin();
            it != V.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

bool Graph::vertexSafe (vector <int> path, int from, int to) {
    /*for (vector <int> :: iterator it = path.begin();
            it != path.begin(); ++it) {
        if ((*it) == to) {
            cout << "vertex " << to << " already in path" << endl;
            return false;
        }
    }*/
    for (vector <int> :: iterator it2 = adj[from].begin();
            it2 != adj[from].begin(); ++it2) {
        CALL;
        cout << (*it2) << " : " << to << endl;
        if ((*it2) == to) {
            return true;
        }
    }
    cout << "vertex " << to << " not reachable from " << from << endl;
    return false;
}

bool Graph::hamiltonPathUtil (vector <int> &path, vector <bool> &visited,
                                int steps, int vertex) {
    if (vertex == size) {
        return true;
    }
    for (vector <int> :: iterator it = adj[vertex].begin();
            it != adj[vertex].end(); ++it) {
        int dest = (*it);
        if (vertexSafe(path, vertex, dest)) {
            path[vertex] = dest;
            if (hamiltonPathUtil(path, visited, ++steps, (vertex+1))) {
                return true;
            }
            path[vertex] = -1;
        }
    }
    return false;
}

bool Graph::hamiltonPath (int vertex) {
    vector <bool> visited(size, false);
    vector <int> path(size, -1);
    path[vertex] = 0; //can start from any point in undirected graph
    
    if ( hamiltonPathUtil(path, visited, 0, 1) == false) {
        cout << "No solution" << endl;
        return false;
    }
    else {
        print(path);
        return true;
    }
}

int main (int argc, char** argv) {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.hamiltonPath(0);
    
    return 0;
}