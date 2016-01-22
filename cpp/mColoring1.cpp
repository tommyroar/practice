#include <iostream>
#include <vector>
#include <queue>

#define CALL std::cout<< __FUNCTION__ <<std::endl;

using namespace std;

typedef vector < vector <int> > vvi;
typedef vector <int> vi;
typedef vector <bool> vb;

class Graph {
    int size;
    vvi adj;
    
    public:
        Graph(int size);
        void addEdge (int from, int to);
        int mColor ();
};

Graph::Graph (int size) {
    this->size = size;
    adj.resize(size);
}

void Graph::addEdge (int from, int to) {
    adj[from].push_back(to);
    adj[to].push_back(from);
}

int Graph::mColor () {
    int max = 0;
    
    vi result(size, -1);
    vb available(size, false);
    result[0] = 0;
    
    for (int u=1; u<size; ++u) {
        vi::iterator iter;
        for (iter = adj[u].begin(); iter != adj[u].end(); ++iter) {
            if (result[*iter] != -1) {
                available[result[*iter]] = true;
            }
        }
        
        int cr;
        for (cr=0; cr<size; ++cr) {
            if (available[cr] == false) {
                break;
            }
        }
        if (cr > max) {
            max = cr;
        }
        result[u] = cr;
        
        for (iter = adj[u].begin(); iter != adj[u].end(); ++iter) {
            if (result[*iter] != -1) {
                available[result[*iter]] = false;
            }
        }
    }
    
    return max;
}

int main (int argc, char** argv) {
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Needed m=" << g1.mColor() << " colors " << endl;
    
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "Needed m=" << g2.mColor() << " colors " << endl;
    
    return 0;
}