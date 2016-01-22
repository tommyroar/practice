#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define CALL std::cout<<__FUNCTION__<<std::endl;

using namespace std;
typedef vector < vector < pair <int,int> > > vvpi;
typedef vector < pair <int,int> > vpi;
typedef pair <int, int> pi;
typedef pair < int, pi > pip;
typedef vector < pip > vpip;
typedef vector <int> vi;

class Graph {
    int size;
    vvpi adj;
    vpip edge;
    vpip mst;
    
    public:
        Graph(int size);
        void addEdge(int from, int to, int weight);
        void KruskalMST(int vertex);
        int findSet(int x, vi &parent);
        void print (vpip graph);
};

Graph::Graph (int size) {
    this->size = size;
    adj.resize(size);
}

void Graph::addEdge (int from, int to, int weight) {
    adj[from].push_back(pi(to, weight));
    edge.push_back(pip(weight, pi(from, to)));
    //pi p = adj[from].back();
    //cout << p.first << " : " << p.second << endl;
}

//find root of set in constant time
int Graph::findSet (int x, vi &parent) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x], parent);
    }
    return parent[x];
}

void Graph::KruskalMST (int vertex) {
    int i, pu, pv, total;
    vi parent(size, 0);
    
    for (i=0; i<size; ++i) {
        parent[i] = i;
    }
    
    sort(edge.begin(), edge.end());
    
    total = 0;
    vpip::iterator it;
    for (it = edge.begin(); it != edge.end(); ++it) {
        pu = findSet((*it).second.first, parent);
        pv = findSet((*it).second.second, parent);
        if (pu != pv) {
            mst.push_back(*it);
            total += (*it).first;
            parent[pu] = parent[pv];
        }
    }
    
    print(mst);
}

void Graph::print (vpip graph) {
    vpip::iterator it;
    for (it = graph.begin(); it != graph.end(); ++it) {
        cout << (*it).second.first << " - " << (*it).second.second
            << " : " << (*it).first << endl;
    }
    cout << endl;
}

int main (int argc, char** argv) {
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.KruskalMST(0);
    
    return 0;
}