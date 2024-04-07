#include <iostream>
#include <list>
using namespace std;
class Graph {
private:
    int vertices;
    list<int>* adjList;
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";
        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }
public:
    Graph(int V) : vertices(V) {
        adjList = new list<int>[V];
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }
    void DFS(int start) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }
        DFSUtil(start, visited);
    }
    void BFS(int start) {
        bool* visited = new bool[vertices];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false;
        }
        visited[start] = true;
        cout << start << " ";
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                cout << i << " ";
            }
        }
        for (int i = 0; i < vertices; ++i) {
            for (auto j = adjList[i].begin(); j != adjList[i].end(); ++j) {
                if (!visited[*j]) {
                    visited[*j] = true;
                    cout << *j << " ";
                }
            }
        }
    }
    ~Graph() {
        delete[] adjList;
    }
};
int main() {
    int vertices, edges, start;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    Graph graph(vertices);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    cout << "Enter starting vertex for traversal: ";
    cin >> start;
    cout << "Depth First Search (DFS): ";
    graph.DFS(start);
    cout << endl;
    cout << "Breadth First Search (BFS): ";
    graph.BFS(start);
    cout << endl;
    return 0;
}