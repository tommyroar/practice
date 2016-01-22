#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

#define SIZE 4
#define CALL \
    std::cout<<__FUNCTION__<<std::endl;

using namespace std;

class Graph {
    int size;
    vector < vector < pair <int, int> > > adj;
    public:
        Graph(int size);
        void addEdge (int from, int to, int weight);
        void APSP ();
        template <size_t rows, size_t cols>
        void print(int (&array)[rows][cols]);
};

Graph::Graph (int size) { 
    this->size = size;
    adj.reserve(size);
}

void Graph::addEdge (int from, int to, int weight) {
    adj[from].push_back(pair <int, int>(to, weight));
}

void Graph::APSP () {
    int mat[SIZE][SIZE];
    int dist[SIZE][SIZE];
    int i, j, k;

    vector < pair <int, int> >::iterator list_iter;
    for (i=0; i<SIZE; ++i) {
        for (j=0; j<SIZE; ++j) {
            if (i=j) {
                mat[i][j] = 0;
                dist[i][j] = 0;
            }
            else {
                mat[i][j] = INT_MAX;
                dist[i][j] = INT_MAX;
            }
        }
        for (list_iter = adj[i].begin(); list_iter != adj[i].end(); ++list_iter) {
            cout << i << " " << list_iter->first << " " << list_iter->second << endl;
            mat[i][list_iter->first] = list_iter->second;
            dist[i][list_iter->first] = list_iter->second;
        }
    }
    print(dist);
    
    for (k=0; k<SIZE; ++k) {
        for (i=0; i<SIZE; ++i) {
            for (j=0; j<SIZE; ++j) {
                /*if (dist[j][i] + dist[i][k] < dist[j][k]) {
                    dist[j][k] = dist[j][i] + dist[i][k];
                }*/
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    print(dist);
}

template <size_t rows, size_t cols>
void Graph::print(int (&array)[rows][cols]) {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            cout << array[i][j] << " ";
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