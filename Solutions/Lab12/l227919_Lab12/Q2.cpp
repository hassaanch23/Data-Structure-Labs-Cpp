//#include <iostream>
//#include <list>
//using namespace std;
//
//class Node {
//public:
//    int id;
//    Node() : id(0) {}
//    Node(int n) : id(n) {}
//};
//
//class Graph {
//public:
//    Node* nodes;
//    list<Node*>* adjacencyList;
//    int size;
//
//    void exploreAndPrint(Node& node, bool* visited) {
//        visited[node.id] = true;
//        cout << node.id << " ";
//
//        for (Node* neighbor : adjacencyList[node.id]) {
//            if (!visited[neighbor->id]) {
//                exploreAndPrint(*neighbor, visited);
//            }
//        }
//    }
//
//    void explore(Node& node, bool* visited) {
//        visited[node.id] = true;
//        for (Node* neighbor : adjacencyList[node.id]) {
//            if (!visited[neighbor->id]) {
//                explore(*neighbor, visited);
//            }
//        }
//    }
//
//    bool detectCycle(Node& node, bool* visited, bool* recursionStack) {
//        visited[node.id] = true;
//        recursionStack[node.id] = true;
//
//        for (Node* neighbor : adjacencyList[node.id]) {
//            if (!visited[neighbor->id]) {
//                if (detectCycle(*neighbor, visited, recursionStack)) {
//                    return true;
//                }
//            }
//            else if (recursionStack[neighbor->id]) {
//                return true;
//            }
//        }
//        recursionStack[node.id] = false;
//        return false;
//    }
//
//    Graph(int n) : size(n) {
//        nodes = new Node[n];
//        adjacencyList = new list<Node*>[n];
//
//        for (int i = 0; i < n; ++i) {
//            nodes[i] = Node(i);
//        }
//    }
//
//    void addEdge(int from, int to) {
//        adjacencyList[from].push_back(&nodes[to]);
//    }
//
//    void printDFS() {
//        bool* visited = new bool[size]();
//        for (int i = 0; i < size; ++i) {
//            if (!visited[nodes[i].id]) {
//                exploreAndPrint(nodes[i], visited);
//            }
//        }
//
//        delete[] visited;
//    }
//
//    void DFS() {
//        bool* visited = new bool[size]();
//        for (int i = 0; i < size; ++i) {
//            if (!visited[nodes[i].id]) {
//                explore(nodes[i], visited);
//            }
//        }
//
//        delete[] visited;
//    }
//
//    bool hasCycle() {
//        bool* visited = new bool[size]();
//        bool* recursionStack = new bool[size]();
//
//        for (int i = 0; i < size; ++i) {
//            if (!visited[nodes[i].id]) {
//                if (detectCycle(nodes[i], visited, recursionStack)) {
//                    return true;
//                }
//            }
//        }
//
//        delete[] visited;
//        delete[] recursionStack;
//        return false;
//    }
//
//    int countConnectedComponents() {
//        bool* visited = new bool[size]();
//        int count = 0;
//
//        for (int i = 0; i < size; ++i) {
//            if (!visited[nodes[i].id]) {
//                explore(nodes[i], visited);
//                ++count;
//            }
//        }
//
//        delete[] visited;
//        return count;
//    }
//
//    ~Graph() {
//        delete[] nodes;
//        delete[] adjacencyList;
//    }
//};
//
//int main() {
//    Graph g(4);
//    g.addEdge(0, 2);
//    g.addEdge(0, 1);
//    g.addEdge(1, 2);
//    g.addEdge(2, 3);
//    g.addEdge(2, 0);
//
//    cout << "Depth First Traversal:\n";
//    g.printDFS();
//
//    bool hasCycle = g.hasCycle();
//    cout << endl << "Detect Cycle : ";
//    if (hasCycle)
//    {
//        cout << "Found";
//    }
//    else
//    {
//        cout << "Not found";
//    }
//    cout << "\nConnected Components: " << g.countConnectedComponents() << endl;
//
//    return 0;
//}
