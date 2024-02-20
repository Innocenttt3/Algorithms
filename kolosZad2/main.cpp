#include <deque>
#include <iostream>
#include <vector>

struct Node {
    std::vector<int> neighbours;
    bool visited = false;
    int value = -1;
};

void BFS(int start, std::vector<Node>&graph, int value) {
    std::deque<Node*> nodesQueue;
    graph[start].visited = true;
    if(graph[start].value == -1) {
        graph[start].value = value;
    }
    nodesQueue.push_back(&graph[start]);
    while (!nodesQueue.empty()) {
        Node *currentNode = nodesQueue.front();
        nodesQueue.pop_front();
        for (int tmp: currentNode->neighbours) {
            if(!graph[tmp].visited) {
                graph[tmp].visited = true;
                if(graph[tmp].value == -1) {
                    graph[tmp].value = value;
                }
                nodesQueue.push_back(&graph[tmp]);
            }
        }

    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int V, E;
    int start, destination;
    std::cin >> V >> E;
    std::vector<Node> graph(V);
    for (int i = 0; i < E; i++) {
        std::cin >> start >> destination;
        graph[start].neighbours.push_back(destination);
        graph[destination].neighbours.push_back(start);
    }
    int value = 1;
    int max = -1;
    for(int i = 0; i < graph.size(); i++) {
        if(graph[i].value == -1) BFS(i, graph, value++);
    }
    for(int i = 0; i < graph.size(); i++) {
        if(graph[i].value > max) {
            max = graph[i].value;
        }
    }
    std::cout << max - 1;
    return 0;
}
